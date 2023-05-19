#include "strings.h"
#include <stdio.h>
#include<stdlib.h>

/*
This library contains our own versions of the core functions in C's string processing library.

Authors: Bryce Anthony and Lydia Catterall
Time Spent: 5 hours
*/

/*
This function calculates the length of a string, excluding the terminating null byte ('\0').
​
Parameters: string - a pointer to the start of a string
Returns: lenCounter - the number of characters in the string
*/
size_t mystrlen(const char* string){
    int lenCounter = 0;
    char stop = '\0';
    while(*(string) != stop){
        string++;
        lenCounter++;
    }
    return lenCounter;
}

/*
This function appends the source string to the destination string, overwriting the  terminating  null  byte ('\0')  at the end of destination, and then adds a terminating null byte.
​
Parameters: destination - a pointer to the string to which source will be
            appended
            source - a pointer to the string to be appended to destination
Returns: destination - a pointer to the resulting string with source appended
         to destination
*/
char *mystrcat(char *destination, const char *source){
    char stop = '\0';
    int destinationStr = mystrlen(destination);
    int sourceStr = mystrlen(source);
    int totalLength = (destinationStr+sourceStr);
    int sourceIndex = 0;
    for(int i = 0; i<(totalLength+1); i++){
        if(i<destinationStr){
            *(destination +i ) = destination[i];
        }
        if(i>=destinationStr){
                *(destination + i ) = source[sourceIndex];
                sourceIndex++;
        }
    }
    int index = 0;
     while(*(destination + index) != stop){
        index++;
    }
     *(destination + index+1) = stop;
    return destination;
}

/*
This function copies the string pointed to by source, including the terminating null byte ('\0'), to the buffer pointed to by destination.
​
Parameters: destination - a pointer to the buffer to which source will be
            copied
            source - a pointer to the string to be copied into destination
Returns: destination - a pointer to the resulting string with source copied
         into it
*/
char* mystrcpy(char *destination, const char *source){
    char stop = '\0';
    //copies string pointed to by src including the terminating byte
     int index = 0;
     while(*(source + index) != stop){
        *(destination + index) = *(source + index);
        index++;
    }
     *(destination + index) = stop;

    return destination;
}

/*
This function compares the two strings s1 and s2.
​
Parameters: s1 - a pointer to the string to be compared to s2
            s2 - a pointer to the string to be compared to s1
Returns: an integer less  than, equal to, or greater than zero if s1 is found
         to be less than, to match, or be greater than s2.
*/
int mystrcmp(const char* s1, const char* s2){
    int s1Length= mystrlen(s1);
    int s2Length= mystrlen(s2);
    int s1Total = 0;
    int s2Total = 0;

    for(int i = 0; i<s1Length; i++){
        int curValue = *(s1 +i);
        s1Total+=curValue;
    }
    for(int i = 0; i<s2Length; i++){
        int curValue = *(s2 +i);
        s2Total+=curValue;
    }
    if(s1Total==s2Total){
        return 0;
    }
    if(s1Total>s2Total){
        return 1;
    }
    else{
        return -1;
    }
}

/*
This function finds the first occurrence of the substring needle in the string haystack.
​
Parameters: haystack - a pointer to the string to be searched through for needle
            needle - a pointer to the substring to be searched for in haystack
Returns: firstOccurrence - a pointer to the  beginning  of the located substring (or NULL if the substring is not found)
*/
char* mystrstr(const char *haystack, const char *needle){
    int lenHaystack = mystrlen(haystack);
    int lenNeedle = mystrlen(needle);
    int flag = 0;
    int checker = 2;
    for(int i= 0; i<(lenHaystack-(lenNeedle-1)); i++){
        char subString[lenNeedle+1];
        flag = 0;
        for(int j=0; j<lenNeedle; j++){
            subString[j] = haystack[i+j];
            //double-checks that the individual characters in subString correspond with the individual characters in needle
            if(subString[j] ==  needle[j]){
                flag++;
            }
        }
        subString[lenNeedle]= '\0';
        if(flag==lenNeedle){
            checker =  mystrcmp(subString, needle);
        }
        if(checker == 0){
            const char *firstOccurrence = (haystack+i);
            return (char *)firstOccurrence;
        }
    }
    return NULL;
}

/*
This function returns a pointer to a new string which is a duplicate of the string s.
​
Parameters: s - a pointer to the string to be duplicated
Returns: dupString - a pointer to a new string which is a duplicate of s
*/
char *mystrdup(const char*s){
    int len = mystrlen(s);
    char *dupString = malloc(sizeof(char)*(len+1));
    if (dupString == NULL) {
        printf("ERROR: malloc failed!\n");
        return NULL;
    }
    mystrcpy(dupString, s);
    return dupString;
}

/*
This function returns a pointer to  the  first occurrence of the character c in the string s.
​
Parameters: s - a pointer to the string to be searched through for c
Returns: s+i - a pointer to the first occurrence of the character c in string s
*/
char *mystrchr(const char*s, int c){
    int length = mystrlen(s);
    char stop = '\0';
    if(c == stop){
        return (char *) (s+length);
    }
    for(int i = 0; i<length; i++){
        int cur = *(s+i);
        if(cur == c){
            return (char *) (s+i);
        }
    }
    return NULL;
}
