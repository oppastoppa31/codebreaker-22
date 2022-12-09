/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'main'
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct runtime__type;
struct runtime_interfacetype;
struct runtime_imethod;
struct runtime_itab;
struct crypto_cipher_cbc;
struct crypto_cipher_cbcEncrypter;
struct crypto_aes_aesCipherGCM;

/* 827 */
typedef crypto_cipher_cbc crypto_cipher_cbc_0;

/* 37 */
typedef runtime_itab runtime_itab_0;

/* 132 */
struct runtime_iface
{
  runtime_itab_0 *tab;
  void *data;
};

/* 131 */
typedef runtime_iface runtime_iface_0;

/* 830 */
typedef runtime_iface_0 crypto_cipher_Block;

/* 829 */
typedef crypto_cipher_Block crypto_cipher_Block_0;

/* 5 */
typedef unsigned __int8 uint8;

/* 92 */
struct _slice_uint8
{
  uint8 *array;
  __int64 len;
  __int64 cap;
};

/* 828 */
struct crypto_cipher_cbc
{
  crypto_cipher_Block_0 b;
  __int64 blockSize;
  _slice_uint8 iv;
  _slice_uint8 tmp;
};

/* 35 */
typedef runtime_interfacetype runtime_interfacetype_0;

/* 9 */
typedef runtime__type runtime__type_0;

/* 3 */
typedef unsigned __int32 uint32;

/* 1 */
typedef unsigned __int64 uintptr;

/* 36 */
struct runtime_itab
{
  runtime_interfacetype_0 *inter;
  runtime__type_0 *_type;
  uint32 hash;
  uint8 _[4];
  uintptr fun[1];
};

/* 4 */
typedef unsigned __int8 runtime_tflag;

/* 6 */
typedef void (*funcunsafe_Pointer_comma__unsafe_Pointer_bool)(void *, void *, bool *);

/* 7 */
typedef __int32 runtime_nameOff;

/* 8 */
typedef __int32 runtime_typeOff;

/* 2 */
struct runtime__type
{
  uintptr size;
  uintptr ptrdata;
  uint32 hash;
  runtime_tflag tflag;
  uint8 align;
  uint8 fieldAlign;
  uint8 kind;
  funcunsafe_Pointer_comma__unsafe_Pointer_bool equal;
  uint8 *gcdata;
  runtime_nameOff str;
  runtime_typeOff ptrToThis;
};

/* 26 */
struct runtime_name
{
  uint8 *bytes;
};

/* 25 */
typedef runtime_name runtime_name_0;

/* 33 */
typedef runtime_imethod runtime_imethod_0;

/* 32 */
struct _slice_runtime_imethod
{
  runtime_imethod_0 *array;
  __int64 len;
  __int64 cap;
};

/* 31 */
struct runtime_interfacetype
{
  runtime__type_0 typ;
  runtime_name_0 pkgpath;
  _slice_runtime_imethod mhdr;
};

/* 34 */
struct runtime_imethod
{
  runtime_nameOff name;
  runtime_typeOff ityp;
};

/* 831 */
typedef runtime_iface_0 crypto_cipher_BlockMode;

/* 832 */
typedef crypto_cipher_BlockMode crypto_cipher_BlockMode_0;

/* 833 */
typedef runtime_iface_0 crypto_cipher_cbcEncAble;

/* 834 */
typedef crypto_cipher_cbcEncAble crypto_cipher_cbcEncAble_0;

/* 835 */
typedef crypto_cipher_cbcEncrypter crypto_cipher_cbcEncrypter_0;

/* 836 */
struct crypto_cipher_cbcEncrypter
{
  crypto_cipher_Block_0 b;
  __int64 blockSize;
  _slice_uint8 iv;
  _slice_uint8 tmp;
};

/* 837 */
typedef __int64 crypto_aes_KeySizeError;

/* 147 */
struct _slice_uint32
{
  uint32 *array;
  __int64 len;
  __int64 cap;
};

/* 838 */
struct crypto_aes_aesCipher
{
  _slice_uint32 enc;
  _slice_uint32 dec;
};

/* 839 */
typedef crypto_aes_aesCipher crypto_aes_aesCipher_0;

/* 840 */
struct crypto_aes_aesCipherAsm
{
  crypto_aes_aesCipher_0 aesCipher;
};

/* 841 */
typedef crypto_aes_aesCipherAsm crypto_aes_aesCipherAsm_0;

/* 842 */
typedef crypto_aes_aesCipherGCM crypto_aes_aesCipherGCM_0;

/* 843 */
struct crypto_aes_aesCipherGCM
{
  crypto_aes_aesCipherAsm_0 aesCipherAsm;
};

/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'main'
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct runtime__type;
struct runtime_eface;

/* 81 */
typedef runtime_eface runtime_eface_0;

/* 80 */
typedef runtime_eface_0 interface__0;

/* 9 */
typedef runtime__type runtime__type_0;

/* 82 */
struct runtime_eface
{
  runtime__type_0 *_type;
  void *data;
};

/* 1 */
typedef unsigned __int64 uintptr;

/* 3 */
typedef unsigned __int32 uint32;

/* 4 */
typedef unsigned __int8 runtime_tflag;

/* 5 */
typedef unsigned __int8 uint8;

/* 6 */
typedef void (*funcunsafe_Pointer_comma__unsafe_Pointer_bool)(void *, void *, bool *);

/* 7 */
typedef __int32 runtime_nameOff;

/* 8 */
typedef __int32 runtime_typeOff;

/* 2 */
struct runtime__type
{
  uintptr size;
  uintptr ptrdata;
  uint32 hash;
  runtime_tflag tflag;
  uint8 align;
  uint8 fieldAlign;
  uint8 kind;
  funcunsafe_Pointer_comma__unsafe_Pointer_bool equal;
  uint8 *gcdata;
  runtime_nameOff str;
  runtime_typeOff ptrToThis;
};
