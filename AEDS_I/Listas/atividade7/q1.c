typedef struct bandas {
    char nome[255];
    char genero[255];
    int numIntegrantes;
    int ranking;

} Bandas;


int main(){    
    Bandas banda1 = {"ACDC", "Rock", 5, 2};
    Bandas banda2 = {"Black Sabbath", "Rock", 3, 1};
    Bandas banda3 = {"My chemical romance", "PopRock", 4, 3};
    Bandas banda4 = {"Nirvana", "Rock", 3, 4};    
    Bandas banda5 = {"BTS", "KPop", 7, 5};

    return 0;
}