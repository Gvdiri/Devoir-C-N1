#include <iostream>
#include <fstream>
using namespace std;


// Exo 1: Fonction PGDC
int PGDC(int m, int n) {
    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

// Exo 2
void DiffSomme(int tab[], int taille) {
    int sommePaire = 0, sommeImpaire = 0;
    for (int i = 0; i < taille; i++) {
        if (tab[i] % 2 == 0)
            sommePaire += tab[i];
        else
            sommeImpaire += tab[i];
    }
    cout << "Difference: " << (sommePaire - sommeImpaire) << endl;
}

// Exo 3
bool Egaux(int tab1[], int tab2[], int taille) {
    for (int i = 0; i < taille; i++) {
        if (tab1[i] != tab2[i])
            return false;
    }
    return true;
}

// Exo 4: 
void EnregistreClients(string clients[], int taille) {
    ofstream fichier("ClientFile.txt");
    if (fichier.is_open()) {
        for (int i = 0; i < taille; i++) {
            fichier << clients[i] << endl;
        }
        fichier.close();
    } else {
        cout << "Erreur d'ouverture du fichier." << endl;
    }
}

// Exo 5: Test
int main() {
    // Test Exo 1
    cout << "PGCD(16,10) = " << PGDC(16,10) << endl;

    // Test Exo 2
    int tab[100];
    for (int i = 0; i < 100; i++) tab[i] = i + 1;
    DiffSomme(tab, 100);

    // Test Exo 3
    int tab1[10] = {1,2,3,4,5,6,0,8,9,10};
    int tab2[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << (Egaux(tab1, tab2, 10) ? "VRAI" : "FAUX") << endl;

    // Test Exo 4
    string clients[10] = {"Gadiri", "Demba", "Modou", "Cherif", "Diallo", "Moussa", "Mignane", "Stevens", "Thiam", "Jibo"};
    EnregistreClients(clients, 10);
    
    return 0;
}
