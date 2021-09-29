#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/pkcs7.h>
#include <openssl/x509.h>
#include <openssl/rand.h>
#include <openssl/objects.h>
#include <openssl/x509v3.h>

using namespace std;

//现在假设我们有一个可信的根CA，其公钥证书为：
const char cacert[] = "\
-----BEGIN CERTIFICATE----- \n\
MIIB/zCCAaagAwIBAgIJAKKa0PAt9M1FMAoGCCqBHM9VAYN1MFsxCzAJBgNVBAYT \n\
AkNOMQ4wDAYDVQQIDAVIdUJlaTEOMAwGA1UEBwwFV3VIYW4xDTALBgNVBAoMBEhV \n\
U1QxDDAKBgNVBAsMA0NTRTEPMA0GA1UEAwwGY2Fyb290MB4XDTIwMDkyMDIwNTkx \n\
OVoXDTMwMDkxODIwNTkxOVowWzELMAkGA1UEBhMCQ04xDjAMBgNVBAgMBUh1QmVp \n\
MQ4wDAYDVQQHDAVXdUhhbjENMAsGA1UECgwESFVTVDEMMAoGA1UECwwDQ1NFMQ8w \n\
DQYDVQQDDAZjYXJvb3QwWTATBgcqhkjOPQIBBggqgRzPVQGCLQNCAASJ8mm28JJR \n\
bZKLr6DCo1+KWimpKEsiTfZM19Zi5ao7Au6YLosyN71256MWmjwkwXxJeLa0lCfm \n\
kF/YWCX6qGQ0o1MwUTAdBgNVHQ4EFgQUAL5hW3RUzqvsiTzIc1gUHeK5uzQwHwYD \n\
VR0jBBgwFoAUAL5hW3RUzqvsiTzIc1gUHeK5uzQwDwYDVR0TAQH/BAUwAwEB/zAK \n\
BggqgRzPVQGDdQNHADBEAiAaZMmvE5zzXHx/TBgdUhjtpRH3Jpd6OZ+SOAfMtKxD \n\
LAIgdKq/v2Jkmn37Y9U8FHYDfFqk5I0qlQOAmuvbVUi3yvM= \n\
-----END CERTIFICATE----- \n\
";

//用户B是PKCS#7格式加密消息的接收者，用户B的私钥为：
const char pkeyB[] = "\
-----BEGIN EC PARAMETERS----- \n\
BggqgRzPVQGCLQ== \n\
-----END EC PARAMETERS----- \n\
-----BEGIN EC PRIVATE KEY----- \n\
MHcCAQEEINQhCKslrI3tKt6cK4Kxkor/LBvM8PSv699Xea7kTXTToAoGCCqBHM9V \n\
AYItoUQDQgAEH7rLLiFASe3SWSsGbxFUtfPY//pXqLvgM6ROyiYhLkPxEulwrTe8 \n\
kv5R8/NA7kSSvcsGIQ9EPWhr6HnCULpklw== \n\
-----END EC PRIVATE KEY----- \n\
";

//将证书转化为X509_st形式
X509 *getX509(const char *cert) {
	BIO *bio;
	bio = BIO_new(BIO_s_mem());
	BIO_puts(bio, cert);
	return  PEM_read_bio_X509(bio, NULL, NULL, NULL);
}

//将私钥转化为EVP_PKEY形式
EVP_PKEY *getpkey(const char *private_key) {
	BIO *bio_pkey = BIO_new_mem_buf((char *)private_key, strlen(private_key));

	if (bio_pkey == NULL)
		return NULL;
	return  PEM_read_bio_PrivateKey(bio_pkey, NULL, NULL, NULL);
}

//主功能函数，generate_pkcs#7
void gen_pkcs7() {
	BIO *bio_out, *mem;
	const EVP_CIPHER *cipher;
	EVP_PKEY *pkey;
	PKCS7 *p7;
	X509 *cert;
	size_t len;
	X509_STORE *ca;
	char buf[70], ans[5000];
	string str="";
	char *out;
	int i, flags, num_signer;
	//私钥转化EVP_PHEY形式
	EVP_PKEY* pKey = getpkey(pkeyB);
	if(pKey == NULL){
		printf("key_ERROR\n");
		return;
	}
	//ca存储证书X509形式
 	ca = X509_STORE_new();
  	X509_STORE_add_cert(ca, getX509(cacert));
	//标准输入，存为str，以换行结尾
 	while(fgets(buf, sizeof(buf), stdin)){
 		str += buf;	
	}
 	str += '\n';
	//char[]转化为string
 	const char *s = str.c_str();
	//见md
	mem = BIO_new_mem_buf(s,strlen(s));

	p7 = PKCS7_new();
	//将BIO形式mem转化为PKCS7形式的p7
	p7 = PEM_read_bio_PKCS7(mem, NULL, NULL, NULL);
	if(p7 == NULL){
		printf("ERROR\n");
		return;
	}
	//解密
	bio_out = PKCS7_dataDecode(p7,pKey,NULL,NULL);
	len = BIO_read(bio_out,ans,sizeof(ans));
	if(len == -2){
		printf("ERROR\n");
		return;
	}
	//见md
	STACK_OF(PKCS7_SIGNER_INFO) *so = PKCS7_get_signer_info(p7);
	if(so == NULL){
		printf("ERROR\n");
		return;
	}
	//栈帧
	num_signer = sk_PKCS7_SIGNER_INFO_num(so);
	PKCS7_SIGNER_INFO *si;
	for(i = 0; i < num_signer; ++i){
		si = sk_PKCS7_SIGNER_INFO_value(so,i);
		X509_STORE_CTX* ct = X509_STORE_CTX_new();
		if(PKCS7_dataVerify(ca,ct,bio_out,p7,si) != 1){
			printf("ERROR\n");
			return;
		}
	}
	//顺着输出ans数组
	for(i = 0; i < len; ++i){
		printf("%c", ans[i]);
	}
}


int main(int argc, char **argv) {
	//加载
	ERR_load_crypto_strings();
	//配置
	OpenSSL_add_all_algorithms();
	//主函数
	gen_pkcs7();
	return 0;
}