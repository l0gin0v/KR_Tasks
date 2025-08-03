#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENLINE 1024

void help(char *argv[]) {
	printf("This program allows the user to structure their task list and mark completed ones.");
	printf("%s <filename> -r (--read)", argv[0]);
	printf("%s <filename> -a (--add) <task>", argv[0]);
	printf("%s <filename> -d (--delete) <number_task>", argv[0]);
}

void show_tasks(char *filename) {
	char buffer[LENLINE];
	FILE *file = fopen(filename, "r");

	if (file) {
		int i = 1;
		while ((fgets(buffer, LENLINE, file)) != NULL) {
			printf("%d) %s", i, buffer);
			++i;
		}
		fclose(file);
	}
}

void add_task(char *filename, char *task) {
	FILE *file = fopen(filename, "a");

	if (file) {
		fputs(task, file);
		fputs("\n", file); // need fix
		fclose(file);
		printf("Task Up!");
	}
}

void delete_task(char *filename, int line_to_del) {
	if (line_to_del == 0) {
		exit(EXIT_FAILURE);
	}

	FILE *original_file, *temp_file;
	char buffer[LENLINE];
	int current_line = 1;

	original_file = fopen(filename, "r");
	temp_file = fopen("temp.txt", "w");

	while (fgets(buffer, sizeof(buffer), original_file)) {
		if (current_line != line_to_del) 
			fputs(buffer, temp_file);
		++current_line;
	}

	fclose(original_file);
	fclose(temp_file);

	remove(filename);
	rename("temp.txt", filename);

	printf("Task Down!");
}

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	char flag = argv[2][1];

	switch (flag) {
		case 'h':
			help(argv);
			break;
		case 'r':
			show_tasks(filename);
			break;
		case 'a':
			add_task(filename, argv[3]);
			break;
		case 'd':
			delete_task(filename, atoi(argv[3]));
			break;
		default:
			printf("Invalid argument. Use -h | --help to show commands.");
			break;
	}

	return 0;
}
