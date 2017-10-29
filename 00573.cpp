//ejercico 00573 The Snail Accepted Uva Online Judge
//link:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=514
#include <iostream>
using namespace std;

class Snail{//creo mi clase snail
private:
	double H;//declaro en privado la variable H
public:
	double U;//hago publico la varoiable U 
protected:
	double D;//y hago protected a mi variable D
public:
	Snail(double _H, double _U, double _D): H(_H) , U(_U) , D(_D){}//constructor en una sola linea
	//todas las funciones al ser publicas puedo heredarlas
	double get_H()const{
		return H;
	}
	double get_U()const{
		return U;
	}
	double get_D()const{
		return D;
	}
	~Snail(void){}//destructor para no acumular basura en cada test
};

class Snail_aux : public Snail{
private:
	double F;//creo una nueva variable en private
public:
	Snail_aux(double _H, double _U , double _D , double _F) : Snail(_H , _U , _D) , F(_F){}
	double get_F()const
	{
		return F;
	}
	double set_F(double new_F){
		F = new_F;
	}
	~Snail_aux(void){}
};

int main(){
 int i = 0;
 double H,U,D,F;
 double height_after_climbing = 0.0;
 while(cin >> H >> U >> D >> F , H != 0){//mientras en los inputs del archivo H no sea 0
 		Snail_aux problem(H,U,D,F);//construyo mi clase snail_aux
 		problem.set_F(problem.get_F()/100 * problem.U);//puedo acceder a U ya que es pulico
 		while(1){//mientras el caracol llegue arriba o falle en el intento
 			i++;
 			height_after_climbing += problem.U;
 			if(height_after_climbing > problem.get_H()){//la funcion get_H() la uso ya que esta en private
 				cout << "success on day " << i << endl;
 				break;
 			}
 			problem.U -= problem.get_F();//F esta en protected por eso le pongo la funcion get_F
 			height_after_climbing -= problem.get_D();
 			if(height_after_climbing < 0.0){//si lo que se resbalo es menor a 0
 				cout << "failure on day " << i << endl;
 				break;
 			}
 			if(problem.U < 0)//si la subida es menor a 0 el caracol no puede subir distancia negativa
 				problem.U = 0;
 		}
 		height_after_climbing = 0.0;//reinicio mis variables
 		i = 0;
 		problem.~Snail_aux();//destruyo mi clase para no almacenar datos basura sino me puede dar memory limit exceeded
 	}
  return 0;
}

