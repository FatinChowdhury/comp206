#include <stdio.h>
#include <string.h>

int areAnagrams(const char* word1, const char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // If the lengths of the words are different, they cannot be anagrams
    if (len1 != len2) {
        return 0;
    }

    int count[256] = {0}; // Assuming ASCII characters

    // Count the frequency of characters in word1
    for (int i = 0; i < len1; i++) {
        count[word1[i]]++;
    }

    // Subtract the frequency of characters in word2
    for (int i = 0; i < len2; i++) {
        count[word2[i]]--;
    }

    // If all counts are zero, the words are anagrams
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
