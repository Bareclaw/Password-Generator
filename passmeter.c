/**
 *
 * A password strength meter and a default password generator,
 * as defined in the CS221 course website for Project 1.
 *
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

bool isStrongPassword(const char * username, const char * password) //function checks if password entered by the user satisfies the requirements for a strong password
{
    int i = 0; //variable to increment through password
    int charcount = 0; //variable to count characters(must be at least 8)
    bool hasUpper = false; //boolean to check if there is at least 1 Uppercase letter
    bool hasLower = false; //boolean to check if there is at least 1 Lowercase letter
    bool hasdigit = false; //boolean to check if there is at least 1 Digit
    bool validchar = false; //check if there are only letters and numbers
    bool similar = false; //check if the password and username are the same
    int consstr = 0; // counts for consecutive string of 4 letters
    int j = 0; //variable to increment through username
    while(*(password + i) != '\0') {
        charcount++;
        if((*(password + i) >= 65 && *(password + i) <= 90) || (*(password + i) >= 97 && *(password + i) <= 122) || (*(password + i) >= 48 && *(password + i) <= 57)) { //check if the character is legal(if it is a letter or number)
            validchar = true;
        }
        if(*(password + i) >= 65 && *(password + i) <= 90) { //check if upper case
            hasUpper = true;
        }
        if(*(password + i) >= 97 && *(password + i) <= 122) { //check if lower case
            hasLower = true;
        }
        if(*(password + i) >= 48 && *(password + i) <= 57) { //check if char is a number
            hasdigit = true;
        }
        if((*(password + i) >= 0 && *(password + i) <= 47) || (*(password + i) >= 58 && *(password + i) <= 64) || (*(password + i) >= 91 && *(password + i) <= 96) || (*(password + i) >= 123 && *(password + i) <= 127)){
            validchar = false;
            return false;
        }
        i++;

    }
    i = 0;
    while(*(password + i)!= '\0' && *(username + j) != '\0') { //while loop to check if the username is in the password(not case sensitive)
        if(*(username + j) >= 'A' && *(username + j) <= 'Z') {
            if(*(password + i) == *(username + j) + 32) {
                similar = true;
                i++;
                j++;
            } else if(*(password + i) == *(username + j)) {
                similar = true;
                i++;
                j++;
            } else {
                i++;
                j = 0;
                similar = false;
            }
        }
        if(*(username + j) >= 'a' && *(username + j) <= 'z') {
            if(*(password + i) == *(username + j) - 32) {
                similar = true;
                i++;
                j++;
            } else if(*(password + i) == *(username + j)) {
                similar = true;
                i++;
                j++;
            } else {
                i++;
                j = 0;
                similar = false;
            }
        } else {
            if(*(username + j) >= '0' && *(username + j) <= '9'){
                if(*(password + i) == *(username + j)) { //check for number in username and check with password
                    similar = true;
                    i++;
                    j++;
                } else {
                    i++;
                    j = 0;
                    similar = false;
                }
            }
        }
    }
    int t = 0;
    while(password[t] != '\0'){
        if(isalpha(password[t])){        
	    	consstr++;
        }
	else{
        consstr = 0;
	}
	if(consstr >= 4){
		break;
	}
        t++;
    }
    if(consstr >= 4 && hasUpper && hasLower && hasdigit && validchar && !similar && charcount >= 8) {
        return true;
    } else {
        return false;
    }

}

bool isStrongDefaultPassword(const char* username, const char* password) //function that checks if the default password satisfies the password requirements
{
    int i = 0; //variable to increment through password
    int charcount = 0; //variable to count characters(must be at least 8)
    bool hasUpper = false; //boolean to check if there is at least 1 Uppercase letter
    bool hasLower = false; //boolean to check if there is at least 1 Lowercase letter
    bool hasdigit = false; //boolean to check if there is at least 1 Digit
    bool validchar = true; //check if there are only letters and numbers
    bool similar = false; //check if the password and username are the same
    int consstr = 0; // counts for consecutive string of 4 letters
    int j = 0; //variable to increment through username
    while(*(password + i) != '\0'){
	charcount++;
        if(!((*(password + i) >= 65 && *(password + i) <= 90) || (*(password + i) >= 97 && *(password + i) <= 122) || (*(password + i) >= 48 && *(password + i) <= 57))) { //check if the character is legal(if it is a letter or number)
            validchar = false;
            printf("Validchar: %d \n", validchar);
	}
        if(*(password + i) >= 65 && *(password + i) <= 90) { //check if upper case
            hasUpper = true;
        }

        if(*(password + i) >= 97 && *(password + i) <= 122) { //check if lower case
            hasLower = true;
        }
        if(*(password + i) >= 48 && *(password + i) <= 57) { //check if char is a number
            hasdigit = true;
        }
        i++;
    }
    i = 0;
    while(*(password + i)!= '\0' && *(username + j) != '\0') { //while loop to check if the username is in the password(not case sensitive)
        if(*(username + j) >= 'A' && *(username + j) <= 'Z') { //section check for Uppercase letter in username and compares with password
            if(*(password + i) == *(username + j) + 32) {
                similar = true;
                i++;
                j++;
            } else if(*(password + i) == *(username + j)) {
                similar = true;
                i++;
                j++;
            } else {
                i++;
                j = 0;
                similar = false;
            }
        }
        if(*(username + j) >= 'a' && *(username + j) <= 'z') { //section checks for lowercase letter in username and compares with password
            if(*(password + i) == *(username + j) - 32) {
                similar = true;
                i++;
                j++;
            } else if(*(password + i) == *(username + j)) {
                similar = true;
                i++;
                j++;
            } else {
                i++;
                j = 0;
                similar = false;
            }
        } else {
            if(*(password + i) == *(username + j)) { //section checks for number in username and compares with password
                similar = true;
                i++;
                j++;
            } else {
                i++;
                j = 0;
                similar = false;
            }
        }
    }
    int t = 0;

    while(password[t] != '\0'){
	if(isalpha(password[t])){
        consstr++;
    }
	else{
        consstr = 0;
    }
    if(consstr >= 4){
        break;
    }
        t++;
    }
    if(consstr >= 4 && hasUpper && hasLower && hasdigit && validchar && !similar && charcount >= 8 && charcount <= 15) { //check if password is strong or not.
        return true;
    } else {
        return false;
    }
}

void generateDefaultPassword(char * default_password, const char * username) //function that generates a default password
{
    int j = 0;
    int min = 8;
    int max = 15;
    int length = (rand() % (max - min) + 1) + min;
    char minchar = 48;
    char maxchar = 122;
    char randchar = (rand() % (maxchar - minchar) + 1) + minchar;
    while(j < length) {
        if((randchar >= 48 && randchar <= 57) || (randchar >= 65 && randchar <= 90) || (randchar >=97 && randchar <= 122)) {
            *(default_password + j) = randchar;
            j++;
        }
        randchar = (rand() % (maxchar - minchar) + 1) + minchar;
    }
    *(default_password + j) = '\0';
    if(isStrongDefaultPassword(username, default_password) == false){ //keep recursively creating a default password until it is strong
        generateDefaultPassword(default_password, username);
    }
}

int main(void) //main
{
    srand(time(0));
    bool strongpass = false;
    char username[100];
    char password[100];
    char defpassword[16];
    
    while(strongpass == false) {
        printf("Enter username: ");
        scanf("%s", username);
        generateDefaultPassword(defpassword, username);
        printf("Generating a default password...\n");
        printf("Generated default password: %s \n", defpassword);
        printf("\nEnter new password: ");
        scanf("%s", password);
        if(isStrongPassword(username, password)){
            printf("Strong password!\n");
            strongpass = true;
        } else{
            printf("Your password is weak. Try again!\n");
       }
    }
    return 0;   
}
