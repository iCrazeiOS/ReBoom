/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library


__attribute__((visibility("hidden")))
@interface HSAppSecurity : XXUnknownSuperclass {
}
+(id)AES256Decrypt:(id)decrypt withKey:(id)key salt:(id)salt;
+(id)AES256Decrypt:(id)decrypt withKey:(id)key;
+(id)AES256Encrypt:(id)encrypt withKey:(id)key salt:(id)salt;
+(id)hashString:(id)string;
+(id)toString:(id)string;
+(id)getSalt128;
+(id)getSalt;
+(id)decrypt:(id)decrypt fallback:(BOOL)fallback;
+(id)decryptData:(id)data withSalt:(id)salt;
+(id)decryptData:(id)data;
+(id)decrypt:(id)decrypt;
+(id)encryptData:(id)data withSalt:(id)salt;
+(id)encryptData:(id)data;
+(id)encrypt:(id)encrypt;
+(id)md5Key;
+(id)key;
@end

