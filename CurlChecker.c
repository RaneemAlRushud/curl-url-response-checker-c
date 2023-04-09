
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen("YOUR_TXT_FILE_NAME.txt", "r");

    if (!file) {
        fprintf(stderr, "Unable to open file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Remove newline character from line
        line[strcspn(line, "\n")] = 0;

        char cmd[MAX_LINE_LENGTH];
        sprintf(cmd, "curl -s -o /dev/null -w '%%{http_code}' %s", line);

        // Open a pipe to the curl command
        FILE *curl_output = popen(cmd, "r");

        if (!curl_output) {
            fprintf(stderr, "Unable to execute curl command\n");
            return 1;
        }

        char output[MAX_LINE_LENGTH];
        fgets(output, MAX_LINE_LENGTH, curl_output);

        int http_code = atoi(output);

        printf("%s -> %d\n", line, http_code);

        // Close the 'curl_output' pipe
        pclose(curl_output);
    }

    fclose(file);

    return 0;
}

