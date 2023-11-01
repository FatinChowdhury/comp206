#include <stdio.h>
#include <string.h>

int areAnagrams(const char* word1, const char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2) {
        return 0;
    }

    int count[256] = {0};

    for (int i = 0; i < len1; i++) {
        count[word1[i]]++;
        count[word2[i]]--;
    }



    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments. Please provide two words.\n");
        return 1;
    }

    if (areAnagrams(argv[1], argv[2])) {
        printf("Anagram\n");
        return 0;
    } else {
        printf("Not an anagram\n");
        return 1;
    }
}
