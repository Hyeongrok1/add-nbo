#include <stdint.h>
#include <stddef.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>

int read_num(char *file_name) {
	// open binary file
	FILE *fp = fopen(file_name, "rb");	
	size_t n = 0;
	uint32_t buf = 0;
	if ((n = fread(&buf, sizeof(uint32_t), 1, fp)) != 0) {
		// read uint32_t num
		// HBO to NBO
		return htonl(buf);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("valid format: ./add-nbo [bin file1] [bin file2]\n");
		exit(1);
	}
	
	uint32_t first_num = read_num(argv[1]);
	uint32_t second_num = read_num(argv[2]);
	uint32_t sum = first_num + second_num;

	printf("%u(%#x) + %u(%#x) = %u(%#x)", first_num, first_num, second_num, second_num, sum, sum);
	return 0;
}
