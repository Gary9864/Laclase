#include <iostream>
#include <vector>
#include <string>

struct InformacionCantante
{
    std::string nombre;
    std::string nacionalidad;
};

struct Album
{
    std::string nombre_album;
    std::string anio_lanzamiento;
    InformacionCantante inf_persona;
    std::vector<std::pair<std::string, std::string>> canciones; // titulo, duracion
};

// Función para solicitar datos de un álbum completo
Album SolicitarDatos()
{
    Album info_album;

    std::cout << "Ingrese el nombre del cantante: ";
    std::cin >> info_album.inf_persona.nombre;

    std::cout << "Ingrese la nacionalidad del cantante: ";
    std::cin >> info_album.inf_persona.nacionalidad;

    std::cout << "Ingrese el nombre del album: ";
    std::cin >> info_album.nombre_album;

    std::cout << "Ingrese el ano de lanzamiento: ";
    std::cin >> info_album.anio_lanzamiento;

    int i = 0;
    char opcion;
    do
    {

        std::string titulo, duracion;
        
        std::cout << "Ingrese el título de la canción " << i + 1 << ": ";
        std::cin >> titulo;
        std::cout << "Ingrese la duración de la canción " << i + 1 << ": ";
        std::cin >> duracion;
        info_album.canciones.push_back({titulo, duracion});
        i++;
        std::cout << "¿Desea ingresar otra canción? (s/n): ";
        std::cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return info_album;
}

// Imprimir información de los álbumes
void Imprimir(const std::vector<Album> &vector_cantante)
{
    for (auto &c : vector_cantante)
    {
        std::cout << "\n============================\n";
        std::cout << "Nombre del artista: " << c.inf_persona.nombre << "\n";
        std::cout << "Nacionalidad: " << c.inf_persona.nacionalidad << "\n";
        std::cout << "Álbum: " << c.nombre_album << "\n";
        std::cout << "Año: " << c.anio_lanzamiento << "\n";

        std::cout << "Cantidad de canciones del album: " << vector_cantante.size();
        std::cout << "Canciones:\n";
        for (auto &cancion : c.canciones)
        {
            std::cout << "  - " << cancion.first << " (" << cancion.second << ")\n";
        }
    }
}

int main()
{
    std::vector<Album> discos;
    char opcion;

    do
    {
        std::cout << "\nRegistro de album\n";
        discos.push_back(SolicitarDatos());

        std::cout << "\nDesea ingresar otro album? (s/n): ";
        std::cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    std::cout << "\nInformación ingresada\n";
    Imprimir(discos);

    return 0;
}