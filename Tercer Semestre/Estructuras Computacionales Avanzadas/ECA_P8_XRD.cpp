#include <windows.h>
#include<iostream>
using namespace std;


class Solution {
public:

	int cost[3][3]; //matriz de costos
	int n, max_match; //n trabajadores y n trabajos
	int lx[3], ly[3]; //etiquetas de X y Y partes
	int xy[3]; //xy[x] - vertice que coincide con x
	int yx[3]; //yx[y] - vertice que coincide con y
	bool S[3], T[3]; //inicailiza S y T en el algoritmo
	int hungara[3]; //descripcion del algoritmo
	int slackx[3]; //hulgarax[y] como un vertice
	int prev_ious[3]; //arreglo para memorizar alternando p

	void init_labels()
	{
		memset(lx, 0, sizeof(lx));
		memset(ly, 0, sizeof(ly));
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				lx[x] = max(lx[x], cost[x][y]);
			}
		}
	}

	void update_labels()
	{
		int x, y;
		int delta = 99999999; //inicializar delta como infinito
		for (y = 0; y < n; y++) {
			//calcular delta usando holgura
			if (!T[y]) { delta = min(delta, hungara[y]); }
		}
		for (x = 0; x < n; x++) {
			//cambiar label X
			if (S[x]){ lx[x] -= delta; }
		}
		for (y = 0; y < n; y++) {
			//cambiar label Y
			if (T[y]){ ly[y] += delta; }
		}
		for (y = 0; y < n; y++) {
			//actualizar matriz hulgara
			if (!T[y]) {
				hungara[y] -= delta;
			}	
		}
	}

	void add_to_tree(int x, int prev_iousx)
		//x - vértice actual,prev_iousx - vértice de X antes de x en la ruta alterna,
        //entonces agregamos bordes (prev_iousx, xy[x]), (xy[x], x)
	{
		S[x] = true; //agregar x a S
		prev_ious[x] = prev_iousx; //argumentando
		for (int y = 0; y < n; y++) {
			//actualizar slacks, porque agregamos un nuevo vértice a S
			if (lx[x] + ly[y] - cost[x][y] < hungara[y])
			{
				hungara[y] = lx[x] + ly[y] - cost[x][y];
				slackx[y] = x;
			}
		}
	}

	void augment() //FUNCION PRINCIPAL DEL ALGORITMO
	{
		if (max_match == n) return; //comprobar si la coincidencia ya es perfecta
		int x, y, root; //contadores y vertice raiz
		int q[3], wr = 0, rd = 0; //q=cola para bfs, wr=escritura y rd=lectura
		//posicion en la fila
		memset(S, false, sizeof(S)); //inicializar conjunto S
		memset(T, false, sizeof(T)); //inicializar conjunto T
		memset(prev_ious, -1, sizeof(prev_ious)); //establecido previous para el arbol alterno

		for (x = 0; x < n; x++) //encontrar la raiz del arbol
		{
			if (xy[x] == -1)
			{
				q[wr++] = root = x;
				prev_ious[x] = -2;
				S[x] = true;
				break;
			}
		}

		for (y = 0; y < n; y++) //inicializando matriz de hungara
		{
			hungara[y] = lx[root] + ly[y] - cost[root][y];
			slackx[y] = root;	
		}
		cout << "\n";
		//segunda parte de la funcion de aumento()
		while (true) //CICLO PRINCIPAL
		{
			while (rd < wr) //arbol de construccion con ciclo bfs
			{
				x = q[rd++]; //vertice actual de la parte X
				for (y = 0; y < n; y++) //hacer a traves de todos los bordes en el grafo de igualdad
					if (cost[x][y] == lx[x] + ly[y] && !T[y])
					{
						if (yx[y] == -1) break; //se encontro un vertice expuesto en Y, entonces
						//ruta de aumento existe
						T[y] = true; //sino, simplemente agregar y a T
						q[wr++] = yx[y]; //agregar el vertice yx[y], que coincide
						//con y, a la fila
						add_to_tree(yx[y], x); //agregar esquinas (x,y) y (y,yx[y]) al arbol
					}
				if (y < n)
					break; //camino de aumento encontrado
			}
			if (y < n)
				break; //camino de aumento encontrado

			update_labels(); //no se encontro la ruta de aumento, asi que modificar las labels

			wr = rd = 0;
			for (y = 0; y < n; y++)
				//en este ciclo agregamos aristas que fueron agregadas al grafo de igualdad como un
				//resultado de mejorar el etiquetado, agregamos borde (slackx[y], y) al arbol si
				//y solo si !T[y] && slack[y] == 0, tambien con este borde agregamos otro
				//(y, yx[y]) o aumentar la coincidencia, si Y estaba expuesto
				if (!T[y] && hungara[y] == 0)
				{
					if (yx[y] == -1) //vertice expuesto en Y encontrado, o sea existe una ruta de aumento
					{
						x = slackx[y];
						break;
					}
					else
					{
						T[y] = true; //agregar a T
						if (!S[yx[y]])
						{
							q[wr++] = yx[y]; //agregar el vertice yx[y], que coincide con y a la cola
							add_to_tree(yx[y], slackx[y]); //agregar (x,y) y (y) al arbol yx[y])
						}
					}
				}
			if (y < n) break; //camino de aumento encontrado
		}

		if (y < n) //encontrando el camino de aumento
		{
			max_match++; //incremento de coincidencia
			//invertimos los bordes a lo largo del camino 
			for (int cx = x, cy = y, ty; cx != -2; cx = prev_ious[cx], cy = ty)
			{
				ty = xy[cx];
				yx[cy] = cx;
				xy[cx] = cy;
			}
			augment(); //guardando datos, regresando al paso 1
		}
	}

	int hungarian()
	{
		int ret = 0; //peso de la coincidencia optima
		max_match = 0; //numero de vértices en la coincidencia actual
		memset(xy, -1, sizeof(xy));
		memset(yx, -1, sizeof(yx));
		init_labels(); //paso 0
		augment(); //paso 1-3
		cout << "\n\nsumando peso de coincidencia optima: ";
		for (int x = 0; x < n; x++) {
			//formando respuesta
			ret += cost[x][xy[x]];
			cout << cost[x][xy[x]] << " ";
			if (x < n-1) {
				cout <<" + ";
			}
		}
		return ret;
	}

	int assignmentProblem(int array[], int N) {
		n = N; //numero de tareas y trabajadores
		cout << "    M A T R I Z   I N I C I A L"<<endl; 
		for (int i = 0; i < n; i++) {
			cout << "\n";
			for (int j = 0; j < n; j++) {
				cost[i][j] = -1 * array[i * n + j];
				cout << "\t"<<cost[i][j]<<" ";
			}	
		}
		int ans = -1 * hungarian();
		cout << "\n\nResultado final costo minimo: ";
		return ans;
	}
};

int main()
{
	int n = 3;
	int array[3 * 3] = { 15,10,9,9,15,10,10,12,8 };
	Solution ob;
	cout << "\n";
	cout << ob.assignmentProblem(array, n) << endl;
}
