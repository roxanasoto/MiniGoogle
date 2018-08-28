#include "CCloud.h"

template <class T>
CCloud<T>::CCloud()
{
	palabra_actual = "";
	documento_actual = -1;
	archivo = NULL;
	ejecutando = false;
}

template <class T>
CCloud<T>::CCloud(T_STRING nombre)
{
	palabra_actual = move(nombre);
	documento_actual = -1;
	archivo = NULL;
	ejecutando = false;
}

template <class T>
T_INT CCloud<T>::Insertar(T_INT id_doc, T_INT bloque)
{
	for (lista & actual : nucleo)
	{
		if (actual.id == id_doc)
		{ 
			actual.contenido.push_back(bloque);
			return 1;
		}
			
	}
	lista nueva;
	nueva.id = id_doc;
	nueva.contenido.push_back(bloque);
	nucleo.push_back(nueva);
	return 2;
}

template <class T>
void CCloud<T>::setName(T_STRING nombre)
{
	palabra_actual = move(nombre);
}

template <class T>
T_INT CCloud<T>::getNumber_doc()
{
	return nucleo.size();
}

template <class T>
void CCloud<T>::guardar()
{
	std::string temp;
	fopen_s(&archivo, ("CCloud\\" + palabra_actual + ".txt").data(), "w+");
	if (archivo == NULL)
		return;

	for (lista & elem : nucleo)
	{
		temp = std::to_string(elem.id);
		for (T_INT & ele_A:elem.contenido)
		{
			temp = temp + " " + std::to_string(ele_A);
		}
		temp = temp + "\n";
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	
	fclose(archivo);
}

template <class T>
void CCloud<T>::Insertar(T_STRING nombre, T_INT id_doc, T_INT bloque)
{
	//obsoleto
	if (!ejecutando)
		abrir_doc(nombre);
	if (nombre.compare(palabra_actual) != 0)
		cambiar_doc(nombre);
	 
	std::string temp;
	if (documento_actual == -1)
	{
		temp = std::to_string(id_doc);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
		documento_actual = id_doc;
		
		temp = " "+std::to_string(bloque);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	else if (documento_actual == id_doc)
	{
		temp = " " + std::to_string(bloque);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	else
	{
		temp = "\n" + std::to_string(id_doc);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);

		temp = " " + std::to_string(bloque);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
		documento_actual = id_doc;
	}

}


template <class T>
void CCloud<T>::abrir_doc(T_STRING nombre)
{
	fopen_s(&archivo, (nombre + ".txt").data(), "w+");
	palabra_actual = nombre;
	ejecutando = true;
}

template <class T>
void CCloud<T>::cambiar_doc(T_STRING nombre)
{
	fclose(archivo);
	fopen_s(&archivo, (nombre + ".txt").data(), "w+");
	palabra_actual = nombre;
	documento_actual = -1;
}

template <class T>
CCloud<T>::~CCloud()
{
	_fcloseall();
}

template<class T>
T_STRING CCloud<T>::GetName()
{
	return palabra_actual;
}

template<class T>
NUMBER_LINES CCloud<T>::GetNumberLines()
{
	return nucleo.size();
}
