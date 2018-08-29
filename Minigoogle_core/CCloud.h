#pragma once

#include "DataTypes.h"
#include "ICloud.h"


class CCloud {
public:
	string id;
	string titulo;
	string body ;
	FILE *archivo;
	FILE *archivo_destino;

	vector<lista> nucleo;
	T_STRING palabra_actual;
	T_INT documento_actual;
	T_BOOL ejecutando;

	int abrir_doc(T_STRING ruta);
	void gen_doc();
	CCloud();
	CCloud(T_STRING ruta);
	~CCloud();
	
};