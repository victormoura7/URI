#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    
    char string[51]; int i;
    
    while (gets(string) != NULL) {
        if (string == '\0') {
            printf("\n");
        }

        if (strlen(string) == 1) {
            printf("%c:%c\n", string[0], string[0]);
        }

        else {
            char alfabeto[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
            
            for (i = 0; i < strlen(string); i++) {
                int letra = string[i] - 97;
                if (alfabeto[letra] == 0){
                    alfabeto[letra]++;
                }
            }
            
            i = 0;
            int virgula = 0;
            
            while (i < 26) {
                char letraInicial, letraFinal;
                if (alfabeto[i] == 1) {
                    letraInicial = i + 97;
                    letraFinal = i + 97;
                    int j = i + 1;
                    
                    while ((alfabeto[j] == 1) && (j < 26)) {
                        letraFinal = j + 97;
                        j++;
                    }

                    i = j + 1;
                    
                    if (virgula == 0) {
                        printf("%c:%c", letraInicial, letraFinal);
                        if (i < 26) {
                            virgula = 1;
                        }
                        else {
                            virgula = 0;
                        }
                    }
                    
                    else {
                        printf(", ");
                        printf("%c:%c", letraInicial, letraFinal);
                        
                        if (i < 26) {
                            virgula = 1;
                        }
                        else {
                            virgula = 0;
                        }
                    }
                }
                else {
                    i++;
                }                
            }
            
            printf("\n");
        }
    }

    return 0;
}
