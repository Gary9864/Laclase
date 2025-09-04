#include <iostream>
#include <vector>
#include <string>
#include <utility>

struct InformacionCantante
{
    std::string nombre;
    std::string nacionalidad;
};

struct Album
{
    std::string nombre_album;
    std::string año_lanzamiento;
    std ::vector<std::pair<std::string, int>> vector_canciones;
    InformacionCantante InformacionGeneralCantante;
};

struct InformacionCantante SolicitarDatos()
{
    Album info_album;
    std::cout << "Ingrese nombre del cantante: " << "\n";
    std::cin >> info_album.InformacionGeneralCantante.nombre;
    std::cout << "Ingrese nacionalidad del cantante: " << "\n";
    std::cin >> info_album.InformacionGeneralCantante.nacionalidad;
    std::cout << "Ingrese el nombre del album: " << "\n";
    std::cin >> info_album.nombre_album;
    std::cout << "Ingrese año de lanzamiento: " << "\n";
    std::cin >> info_album.año_lanzamiento;

    return info_album.InformacionGeneralCantante;
}

void Imprimir(std::vector<struct InformacionCantante> cantante)
{
    for (auto c : cantante)
    {
        std::cout << "Nombre del artista: " << c.nombre << "\n";
        std::cout << "nacionalidad del artista: " << c.nacionalidad << "\n";

    }
}

int main()
{
    std::vector<InformacionCantante> mi_vector; 
    // Imprimir; // Error: así no se llama a una función
    Imprimir(vector);
    return 0;
}