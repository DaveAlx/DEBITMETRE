
// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

//lisste des include necessaires pour faire fonctinner le programme
#include <xc.h>
#include <string.h>
//définier la fréquance d'oscillation
#define _XTAL_FREQ 16000000
//déclaration des variables 
//c'est la variable qui va permettre d'envoyer des données
int chbr = 0; //c'est la variable qui va permettre d'envoyer des données
int vol;




void config() {
    PSA = 0;
    PS0 = 1;
    PS1 = 1;
    PS2 = 1;
    TXEN = 1;
    SYNC = 0;
    BRGH = 1;
    SPBRG = 129;
    SPEN = 1;
    CREN = 1; //activation de la reception de données
    GIE = 1; //interruption globale 
    PEIE = 1; //interruprion des périphiques 
    RCIE = 1; //interruption pour la recption de données
    RBIE = 1; // interruption sur le port B activée
    EEIE = 1; //imnterruption sur l'écriture et la lecture des données stockées en mémoire
}

void uart_txChar(unsigned char ch) { // initialisation de l'envoi des données
    while (!TRMT);
    TXREG = ch;
}



void uart_txStr(unsigned const char *str) { // fonction pour l'envoi de caractères
    while (*str != '\0') {
        uart_txChar(*str);
        str++;
    }

    uart_txChar('\r');
    uart_txChar('\n');

}




void interrupt jdk1() { // fonction d'interruption
    if (RCIF) {
        RCIF = 0;
            if (RCREG == 'I') { // lorsque le programme recoit le caractère I il affiche Bienvenue
                uart_txStr("\rBIENVENUE ");
                 

    }

    if (RBIF) {
    }
    RBIF = 0;
    }
}

void main (void) {
    config();
    while (1);
}
/*   if (RCREG == 'A') {// lorsque le programme recoit le caractère A il affiche l'index de la chambre n°1
                        uart_txStr("\rINDEX CHAMBRE 1 :");
                //ReadEEprom(0x0A); //ici il affiche la valeur de la variable de stockage de volume
                        chbr == 1;
                    }
                    if (RCREG == 'B') {// lorsque le programme recoit le caractère B il affiche l'index de la chambre n°2
                        uart_txStr("\rINDEX CHAMBRE 2 :");
                     }
                    if (RCREG == 'C') {// lorsque le programme recoit le caractère C il affiche l'index de la chambre n°3
                        uart_txStr("\rINDEX CHAMBRE 3 :");
                    }
                    if (RCREG == 'D') {// lorsque le programme recoit le caractère D il affiche l'index de la chambre n°4
                        uart_txStr("\rINDEX CHAMBRE 4 :");
                    }
                    if (RCREG == 'E') {// lorsque le programme recoit le caractère E il affiche l'index de la chambre n°5
                        uart_txStr("\rINDEX CHAMBRE 5 :");
                    }
                    if (RCREG == 'Q') {// lorsque le programme recoit le caractère Q il affiche quitter 
                        uart_txStr("\rA BIENTOT");
                    }
            } */