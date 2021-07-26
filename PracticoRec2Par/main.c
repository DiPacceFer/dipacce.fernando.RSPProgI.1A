#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo* vehiculo_new();
eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipoStr, char* pesoStr);
int vehiculo_setId(eVehiculo* this,int id);
int vehiculo_getId(eVehiculo* this,int* id);
int vehiculo_setMarca(eVehiculo* this,char* marca);
int vehiculo_getMarca(eVehiculo* this,char* marca);
int vehiculo_setTipo(eVehiculo* this,int tipo);
int vehiculo_getTipo(eVehiculo* this,int* tipo);
int vehiculo_setPeso(eVehiculo* this,int peso);
int vehiculo_getPeso(eVehiculo* this,int* peso);

int main()
{
    eVehiculo* vehiculo1=NULL;
    eVehiculo* vehiculo2=NULL;


    vehiculo1=vehiculo_newParametros("1234", "Honda", "1", "243.5");
    FILE* f = fopen("vehiculo.csv", "r");
	if(f == NULL)
    {
		printf("No se pudo abrir el archivo\n");
	    exit(1);
    }

    fprintf(f, "%d,%s,%d,%f\n", vehiculo1->id, vehiculo1->marca, vehiculo1->tipo, vehiculo1->peso);

    fclose(f);

    vehiculo2=vehiculo_newParametros("1235", "Chevrolet", "2", "254.6");
	FILE* e= fopen("vehiculo.bin", "wb");
    if(e==NULL)
    {
        printf("No se pudo abrir archivo\n");
        exit(1);
    }
    fwrite(vehiculo2, sizeof(eVehiculo), 1, e);
    fclose(e);

    return 0;
}

eVehiculo* vehiculo_new()
{
	eVehiculo* nuevoVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
	    if(nuevoVehiculo != NULL)
	    {
	        nuevoVehiculo->id = 0;
	        strcpy(nuevoVehiculo->marca, "");
	        nuevoVehiculo->tipo = 0;
	        nuevoVehiculo->peso = 0;

	    }
	    return nuevoVehiculo;
}
eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipoStr, char* pesoStr)
{
	eVehiculo* nuevoVehiculo = vehiculo_new();
	    if(nuevoVehiculo != NULL)
	    {
	        if(!(vehiculo_setId(nuevoVehiculo, atoi(idStr)) &&
	           vehiculo_setMarca(nuevoVehiculo, marcaStr)&&
	             vehiculo_setTipo(nuevoVehiculo, atoi(tipoStr))&&
	             vehiculo_setPeso(nuevoVehiculo, atoi(pesoStr))))
	        {
	          nuevoVehiculo = NULL;
	        }
	    }
	    return nuevoVehiculo;
}
int vehiculo_setId(eVehiculo* this,int id)
{
	int isOk=0;
	    if(this != NULL && id > 0)
	    {
	        this->id = id;
	        isOk=1;
	    }
	    return isOk;
}
int vehiculo_getId(eVehiculo* this,int* id)
{
	int isOk=0;
	if(this != NULL && id != NULL)
	    {
	        *id = this->id;
	        isOk=1;
	    }
	    return isOk;
}

int vehiculo_setMarca(eVehiculo* this,char* marca)
{
	int isOk=0;
	    if(this != NULL && marca != NULL && strlen(marca) < 20)
	    {
	        strcpy(this->marca, marca);
	        isOk= 1;
	    }
	    return isOk;
}
int vehiculo_getMarca(eVehiculo* this,char* marca)
{
	int isOk=0;
	if(this != NULL && marca != NULL)
	{
		strcpy(marca, this->marca);
	    isOk=1;
    }
	return isOk;
}

int vehiculo_setTipo(eVehiculo* this,int tipo)
{
	int isOk=0;
	if(this != NULL && tipo > 0)
	{
		this->tipo = tipo;
        isOk=1;
	}
	return isOk;
}
int vehiculo_getTipo(eVehiculo* this,int* tipo)
{
	int isOk=0;
	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		isOk=1;
    }
	return isOk;
}

int vehiculo_setPeso(eVehiculo* this,int peso)
{
	int isOk=0;
	if(this != NULL && peso > 0)
	{
		this->peso = peso;
	    isOk=1;
	}
	return isOk;
}
int vehiculo_getPeso(eVehiculo* this,int* peso)
{
	int isOk=0;
	if(this != NULL && peso != NULL)
	{
		*peso = this->peso;
        isOk=1;
	}
	return isOk;
}
