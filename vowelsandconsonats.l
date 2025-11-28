//find the number of vowels and consonats in an input string
%{ 
int vowel_count=0; 
int consonant_count=0; 
%} 
%% 
[aeiouAEIOU] {vowel_count++;} 
[a-zA-Z] {consonant_count++;} 
%% 
int yywrap(){} 
int main(){ 
printf("Enter the string of vowels and consonants:"); 
yylex(); 
printf("no.of vowels are:%d\n",vowel_count); 
printf("no.of consonants are:%d\n",consonant_count); 
return 0; 
}
