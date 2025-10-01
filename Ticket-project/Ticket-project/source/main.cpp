#include"Prerequisites.h"
#include"TicketGestor.h"
/**
 * @brief Función principal del programa.
 *
 * Gestiona un sistema de tickets mediante un menú interactivo.
 * El usuario puede crear, visualizar, buscar, actualizar y eliminar tickets.
 *
 * @return int Código de salida del programa (0 si finaliza correctamente).
 */
int main()

{
	Fecha fecha;//objeto de la clase Fecha
	fecha.getFecha();//llamada al metodo getFecha para obtener la fecha actual
	// menú para interactur con el usuario

    TicketGestor gestor;// Objeto encargado de gestionar los tickets

    int opcion = 0;


    std::cout << "Gestion de Tickets" << std::endl;



    while (opcion != 7) {
        /**
         * @brief Menú principal mostrado al usuario.
         */
        std::cout << "--- BIENVENIDO ---" << std::endl;
        std::cout << "1. Crear nuevo ticket" << std::endl;
        std::cout << "2. Ver todos los tickets" << std::endl;
        std::cout << "3. Buscar ticket por ID" << std::endl;
        std::cout << "4. Cambiar estado de un ticket" << std::endl;
        std::cout << "5. Eliminar un ticket" << std::endl;
        std::cout << "6. Eliminar todos los tickets" << std::endl; 
        std::cout << "7. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        std::cin.ignore();// Limpiar el buffer de entrada

        switch (opcion) {
        case 1: { // @brief Crear nuevo ticket
            std::string titulo, descripcion;

            std::cout << "Ingrese el titulo del ticket:";
            std::getline(std::cin, titulo);

            std::cout << "Ingrese la descripcion del ticket: ";
            std::getline(std::cin, descripcion);

            /**
             * @details
             * - Se crea un ticket con título y descripción dados.
             * - El estado inicial es ABIERTO.
             * - La fecha se asigna automáticamente a la actual.
             */
			Ticket nuevoTicket(titulo, descripcion);
            gestor.agregarTicket(nuevoTicket);// lo aggrego al gestor de tickets

            std::cout << "Ticket creado..." << std::endl;
            std::cout << "------------------------" << std::endl;
            break;
        }

        case 2: { // @brief Mostrar todos los tickets
            std::cout << "LISTA DE TICKETS" << std::endl;
            std::vector<Ticket> todosLosTickets = gestor.getAllTickets();
			// aquí obtengo una copia de todos los tickets que tengo en el gestor
			//el vector es mi lista de tickets
            //asiganno con el =
			// congestor.getAllTickets() me devuelve una copia de todos los tickets
            if (todosLosTickets.size() == 0) {
                //.size devuelve el numero de elementos q hay en el vector
                std::cout << "No hay tickets creados aun." << std::endl;
            }
            else {
                for (int i = 0; i < todosLosTickets.size(); i++) {
					//accedo al ticket en la posicion i del vector
                    //Para cada posición i desde 0 hasta el tamaño del vector
                    //si i es menor que la cantidad total de tickets
                    // entonces aumenta i en 1 y repite
					std::cout << "------------------------" << std::endl;
                    std::cout << "ID: " << todosLosTickets[i].getId() << std::endl;
					//llamo al metodo getId para obtener el id del ticket
                    std::cout << "Titulo: " << todosLosTickets[i].getTitulo() << std::endl;
                    std::cout << "Estado: ";
                    todosLosTickets[i].mostrarEstado();
                    std::cout << "Fecha: " << todosLosTickets[i].getFecha() << std::endl;
                }
            }
            break;
        }

        case 3: {// @brief Buscar ticket por ID
            int id;

            std::cout << "------------------------" << std::endl;
            std::cout << "Ingrese el ID del ticket: ";
            std::cin >> id;

            Ticket* ticket = gestor.getTicket(id);
			// obtengo un puntero al ticket con el id proporcionado para asi buscarlo
            if (ticket != nullptr) {// si encuentra el ticket
				//nullptr es un puntero que noa apunta a nada 
				// si el puntero no es nulo, pues se enocntro el ticket
                std::cout << "\n";
                ticket->mostrarInfo();
                //ticket mi puntero
				//acceso con la flecha al metodo mostrarInfo para mostrar la info
            }
			else {// si no se encuentra mi ticket
                std::cout << "No se encontró el ticket con id: " << id << std::endl;
            }
            break;
        }

        case 4: {// @brief Cambiar estado de un ticket
            int id, nuevoEstado;
            std::cout << "------------------------" << std::endl;
            std::cout << "Ingrese el ID del ticket: ";
            std::cin >> id;

            Ticket* ticket = gestor.getTicket(id);//buscamos el ticket

            if (ticket != nullptr) {
                std::cout << "Ticket encontrado:" << std::endl;
                std::cout << "Titulo: " << ticket->getTitulo() << std::endl;
                std::cout << "Estado actual: ";
                ticket->mostrarEstado();

                std::cout << "------------------------" << std::endl;
                std::cout << "Seleccione el nuevo estado:" << std::endl;
                std::cout << "0. ABIERTO" << std::endl;
                std::cout << "1. EN_PROGRESO" << std::endl;
                std::cout << "2. COMPLETADO" << std::endl;
                std::cout << "Opcion: ";
                std::cin >> nuevoEstado;

                if (nuevoEstado >= 0 && nuevoEstado <= 2) {//validamos que la opcion se de 0 a 2
                
                    ticket->setEstado(static_cast<Estado>(nuevoEstado));
					//convierte el número a tipo Estado y actualiza el estado del ticket
					// el static_cast ahce mi jconversión de
                    //enum(0,1,2,3) a int(abierto,en_progreso, completado)
                    std::cout << "Estado actualizado" << std::endl;
                    std::cout << "Nuevo estado: ";
                    ticket->mostrarEstado();
                }
                else {
                    std::cout << "Opción invalida." << std::endl;
                }
            }
            else {
                std::cout << "No se encontró un ticket con id: " << id << std::endl;
            }
            break;
        }

        case 5: { //@brief Eliminar ticket por ID
            int id;
            std::cout << "------------------------" << std::endl;
            std::cout << "Ingrese el ID del ticket a eliminar: ";
            std::cin >> id;

            gestor.eliminarTicket(id);
            break;
        }

        case 6: { // @brief Eliminar todos los tickets
            char confirmar;
            std::cout << "------------------------" << std::endl;
            std::cout << "¿Esta seguro de eliminar todos los tickets? (s/n): ";
            std::cin >> confirmar;

			if (confirmar == 's' || confirmar == 'S') {//sin importar mayuscula o minuscula
				gestor.eliminarTodosLosTickets();// llamo al metodo para eliminar todos los tickets
                std::cout << "Todos los tickets han sido eliminados." << std::endl;
            }
            else {
                std::cout << "Operacion cancelada." << std::endl;
            }
            break;
        }

        case 7: {// @brief Salir del programa
        std::cout << "Saliendo del programa..." << std::endl;
        break;
		}

        default: {
            std::cout << "------------------------" << std::endl;
            std::cout << "Opcion invalida, por favor selecciona del 1 al 5." << std::endl;
            break;
        }
        }
    }

    return 0;
}