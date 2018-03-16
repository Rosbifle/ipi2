#include"structures.h"

bool test_zone_limite(action ac, grille g){
	if（ac.orientation == rot_0 || ac.orientation == rot_180）{
		if(ac.x + 1 <= g.sz - 1 && ac.y + 2 <= g.sz - 1) return true;
		else return false;
	}
	else if（ac.orientation == rot_90 || ac.orientation == rot_270）{
		if(ac.x + 2 <= g.sz - 1 && ac.y + 1 <= g.sz - 1) return true;
		else return false;
	}
	else return false;

}

int village_ville(grille g){
	int taille = 0;
	int i, j;
	for(i = 0; i < g.sz; i++){
		for(j = 0; j< g.sz; j++){
			grille gr = init_grid(g.sz);
			int sz = gr.sz;
			int nombre = 0;/*lin shi bian liang, dai biao mei yi ci de taille*/
			if(gr.grid[i][j] == 'v'){
				gr.grid[i][j] = '0';
				nombre++;
				for(i = 0; i < sz; i++){
					for(j = 0; j< sz; j++){
						if(gr.grid[i][j] = '0'){
							if(gr.grid[i+1][j] == 'v'){  
						       gr.grid[i+1][j] = '0';
							   nombre++;   
						    } 					    
						    if(gr.grid[i][j+1] == 'v'){
						       gr.grid[i][j+1] = '0';
							   nombre++;   
						    }    
						    if(gr.grid[i-1][j] == 'v'){  
						       gr.grid[i-1][j] = '0';
							   nombre++;   
						    }  
						    if(gr.grid[i][j-1] == 'v'){  
						       gr.grid[i][j-1] = '0';
							   nombre++;   
						    }
						}
					}
				}//jie shu yi ge dian
				if(nombre > taille){
					taille = nombre;
				}
			}
		}
	}

}



