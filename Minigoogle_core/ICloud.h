#pragma once
#include "DataTypes.h"

template <class T>
class ICloud {
public:
	virtual T_INT Insertar(T_INT, T_INT) = 0;
};


