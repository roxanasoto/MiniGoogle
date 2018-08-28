#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/ICloud.h"


template <class T>
class CCloud : virtual public ICloud<T> {
private:
	vector<lista> nucleo;
	T_STRING palabra_actual;
	T_INT documento_actual;
	FILE *archivo;
	T_BOOL ejecutando;
	void abrir_doc(T_STRING nombre);
	void cambiar_doc(T_STRING nombre);
public:
	CCloud();
	CCloud(T_STRING nombre);
	~CCloud();
	T_STRING GetName();
	NUMBER_LINES GetNumberLines();	
	T_INT Insertar(T_INT id_doc, T_INT bloque);
	void setName(T_STRING nombre);
	T_INT getNumber_doc();
	void guardar();
	void Insertar(T_STRING nombre, T_INT id_doc, T_INT bloque);//obsoleto
};