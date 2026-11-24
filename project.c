#include <stdio.h>
#include <string.h>

int main(void) {
    int choice;
    char input[256], output[256], key[256];
    FILE *in, *out;
    int ch, i = 0;

    printf("\n======================================== \n");
    printf("   FILE ENCRYPTION AND DECRYPTION SYSTEM\n");
    printf("======================================== \n\n");

    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d", &choice);

    printf("Input file: ");
    scanf("%255s", input);

    printf("Output file: ");
    scanf("%255s", output);

    printf("Passkey (up to 255 characters): ");
    scanf("%255s", key);

    in = fopen(input, "rb");
    if (in == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    out = fopen(output, "wb");
    if (out == NULL) {
        printf("Could not create output file.\n");
        fclose(in);
        return 1;
    }

    while ((ch = fgetc(in)) != EOF) {
        fputc(ch ^ key[i % strlen(key)], out);
        i++;
    }

    fclose(in);
    fclose(out);

    if (choice == 1) {
        printf("\nDone! File is encrypted.\n");
        printf("Use the same passkey to decrypt it.\n");
    }
    else if (choice == 2) {
        printf("\nDone! File is decrypted.\n");
    } else {
        printf("\nInvalid choice.\n");
    }

    return 0;
}