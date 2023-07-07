#include <stdint.h>
#include <stddef.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>

int read_num(char *file_name) {
	// open binary file
	FILE *fp = NULL;
	if ((fp = fopen(file_name, "rb")) == NULL) {
		printf("failed to open %s\n", file_name);
		exit(1);
	};	

	size_t n;
	uint32_t buf;
	if ((n = fread(&buf, 1, sizeof(uint32_t), fp)) == sizeof(uint32_t)) {
		// read uint32_t num
		// NBO to HBO
		return ntohl(buf);
	} else {
		printf("failed to read 4 bytes from %s\n", file_name);
		exit(1);
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

	printf("%u(%#x) + %u(%#x) = %u(%#x)\n", first_num, first_num, second_num, second_num, sum, sum);
	return 0;
}
