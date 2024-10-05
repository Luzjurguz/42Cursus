/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cholo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/03 13:17:21 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**archivo(int fd)
{
	char	*str;
	char	*str2;
	char	**mapa;

	str2 = get_next_line(fd);
	if (str2 == NULL)
		return(NULL);
	str = NULL;
	while (str2 != NULL)
	{
		str = ft_strjoin(str, str2);
		str2 = get_next_line(fd);
	}
	mapa = ft_split(str, '\n');
	return (mapa);
}
int	murosmax(char **mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapa[y] != NULL)
	{
		if (mapa[y][x] == '1')
			y++;
		else
			return (1);
	}
	y--;
	while (mapa[y][x] != '\0')
	{
		if (mapa[y][x] == '1')
			x++;
		else
			return (1);
	}
	return (0);
}

int	muros(char **mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapa[y + 1] != NULL)
		y -= -1;
	while (mapa[y][x + 1] != '\0')
		x++;
	while (y >= 0)
	{
		if (mapa[y][x] == '1')
			y--;
		else
			return (1);
	}
	y++;
	while (x > 0)
	{
		if (mapa[y][x] == '1')
			x--;
		else
			return (1);
	}
	return (murosmax(mapa));
}

int recto(char **mapa)
{
	int cnt;
	int ref;
	int cnt2;
	
	ref = 0;
	cnt2 = 0;
	cnt = 0;
	while(mapa[0][cnt] != '\0')
		cnt++;
	ref = cnt;
	while(mapa[cnt2] != NULL)
	{
		if(cnt == ref)
		{
			cnt2++;
			cnt = 0;
			while(mapa[cnt2] != NULL && mapa[cnt2][cnt] != '\0')
				cnt++;
		}
		else
		{
			printf("El mapa no es rectangular\n");
			return(1);
		}
	}
	return(0);
}

int	ft_validchar(char **mapa)
{
	int	ce = 0;
	int	eh = 0;
	int	pnj = 0;
	int	y;
	int	x;
	
	y = 0;
	while (mapa[y] != NULL)
	{
		x = 0;
		while (mapa[y][x] != '\0')
		{
			if (mapa[y][x] == 'E')
				eh++;
			if (mapa[y][x] == 'P')
				pnj++;
			if (mapa[y][x] == 'C')
				ce++;
			x++;
		}
		y++;
	}
	if (eh != 1 || ce < 1 || pnj != 1)
	{
 		printf("mapa inválido\n");
		return(-1);
	}
	return(ce);
}

int only(char **mapa)
{
	int y;
	int x;
	
	y = 0;
	while (mapa[y] != NULL)
	{
		x = 0;
		while(mapa[y][x] != '\0')
		{
			if(mapa[y][x] == 'E' || mapa[y][x] == 'P'||mapa[y][x] == 'C'||
			 mapa[y][x] == '0'|| mapa[y][x] == '1')
			x++;
			else
			{
				printf("El mapa contiene carácteres inválidos\n");
				return(1);
			}
		}
		y++;
	}
	return(0);
}

void boia_ber(char *str)
{
	int cnt;
	cnt = 0;
	
	while(str[cnt] != '.' && str[cnt] != '\0')
		cnt++;
	if(str[cnt] == '.' && str[cnt + 1] != '\0')
	{ 
		cnt++;
		if(str[cnt] == 'b' && str[cnt + 1] != '\0')
			cnt++;
		if(str[cnt] == 'e' && str[cnt + 1] != '\0')
			cnt++;
		if(str[cnt] == 'r')
			cnt++;
		if(str[cnt] == '\0')
			return ;
	}
	printf("[ERROR] ERROR EXTENSIÓN!!\n");
	exit(1);
}

int flotfil(char **mapa, int x, int y)
{
	int cnt;
	
	cnt = 0;
	if (mapa[y][x] != '1' && mapa[y][x] != 'H')
	{
		if(mapa[y][x] == 'C')
			cnt++;
		if(mapa[y][x] == 'E')
			cnt++;
		mapa[y][x] = 'H';
		cnt += flotfil(mapa, x + 1, y);
		cnt += flotfil(mapa, x, y + 1);
		cnt += flotfil(mapa, x - 1, y);
	 	cnt += flotfil(mapa, x, y - 1);
 	}
	return(cnt);
}

void ft_pos(t_cholo *cholo)
{ 
	int x;
	int y; 
	
	y = 0;
	while (cholo->mapa[y] != NULL)
	{ 
		x = 0;
		while(cholo->mapa[y][x])
		{
			if(cholo->mapa[y][x] == 'P')
			{
				cholo->pj_x = x;
				cholo->pj_y = y;
			}
			x++;
		}
		cholo->an = x;
		y++;
	}
	cholo->al = y;
}
char **fri(char **mapa)
{
	int cnt;
	
	 cnt = 0;
	if(mapa)
	{
		while(mapa[cnt])
		{
			free(mapa[cnt]);
			cnt++;
		}
		free(mapa);
	}
	return(NULL);
}

void textu(t_cholo *cholo)
{
	mlx_texture_t *textu;
	int cnt;
	
	textu = mlx_load_png("textu/suelo.png");
	cholo->suelo = mlx_texture_to_image(cholo->venti,textu);
	mlx_delete_texture(textu);
	textu = mlx_load_png("textu/pj.png");
	cholo->pnj = mlx_texture_to_image(cholo->venti,textu);
	mlx_delete_texture(textu);
	textu = mlx_load_png("textu/muro.png");
	cholo->muro = mlx_texture_to_image(cholo->venti,textu);
	mlx_delete_texture(textu);
	textu = mlx_load_png("textu/sal.png");
	cholo->sal= mlx_texture_to_image(cholo->venti,textu);
	mlx_delete_texture(textu);
	cnt = 0;
	cholo->colec = malloc(sizeof(cholo->ce + 1));
	while(cnt < cholo->ce)
	{
		textu = mlx_load_png("textu/colec.png");
		cholo->colec[cnt] = mlx_texture_to_image(cholo->venti,textu);
		mlx_delete_texture(textu);
		cnt++;
	}
}
void pj(t_cholo *cholo, int cnt, int cnt2)
{
	mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt *64);
	mlx_image_to_window(cholo->venti, cholo->pnj, cnt2 * 64, cnt *64);
}
void sal(t_cholo *cholo, int cnt, int cnt2)
{
	mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt *64);
	mlx_image_to_window(cholo->venti, cholo->sal, cnt2 * 64, cnt *64);
	cholo->sal->enabled = false;
}
void colec(t_cholo *cholo, int cnt, int cnt2)
{
	static int cnt3 = 0;
	 
	mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt *64);
	if(cnt3 <  cholo->ce)
	{
		mlx_image_to_window(cholo->venti, cholo->colec[cnt3], cnt2 * 64, cnt *64);
		cnt3++;
	}
}

void venticarglass(t_cholo *cholo, char **mapa)
{
	int cnt;
	int cnt2;
	
	cnt = 0;
	while(mapa[cnt])
	{
		cnt2 = 0;
		while(mapa[cnt][cnt2])
		{
			if(mapa[cnt][cnt2] == 'P')
				pj(cholo, cnt,cnt2);
			cnt2++;
		}
		cnt++;
	}
}

void venticar(t_cholo *cholo, char **mapa)
{
	int cnt;
	int cnt2;
	
	cnt = 0;
	while(mapa[cnt])
	{
		cnt2 = 0;
		while(mapa[cnt][cnt2])
		{
			if(mapa[cnt][cnt2] == '0')
				mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt *64);
			if(mapa[cnt][cnt2] == '1')
				mlx_image_to_window(cholo->venti, cholo->muro, cnt2 * 64, cnt *64);
			if(mapa[cnt][cnt2] == 'E')
				sal(cholo,cnt,cnt2);
			if(mapa[cnt][cnt2] == 'C')
				colec(cholo, cnt,cnt2);
			cnt2++;
		}
		cnt++;
	}
	venticarglass(cholo, mapa);
}
void mov(t_cholo *cholo, int32_t *posy, int32_t *posx, char wasd)
{
	if(wasd == 'W')
		*posy -= 64;
	if(wasd == 'S')
		*posy += 64;
	if(wasd == 'A')
		*posx -= 64;
	if(wasd == 'D')
		*posx += 64;
	cholo->pas++;
	ft_putstr_fd("pasos: ", 0);
	ft_putnbr_fd(cholo->pas, 0);
	ft_putstr_fd("\n", 0);
}
int sepisa( char **mapa, int32_t posy, int32_t posx, char wasd)
{
	if(wasd == 'W')
		if(mapa[posy -1][posx] == '1')
			return(1);
	if(wasd == 'S')
		if(mapa[posy +1][posx] == '1')
			return(1);
	if(wasd == 'A')
		if(mapa[posy][posx-1] == '1')
			return(1);
	if(wasd == 'D')
		if(mapa[posy][posx+1] == '1')
			return(1);
	return(0);
}


void hoooook( mlx_key_data_t tecla, void *chostruc)
{
	t_cholo *cholo;
	int32_t *posx;
	int32_t *posy;
	
	cholo = chostruc;
	posx = &cholo->pnj->instances[0].x;
	posy = &cholo->pnj->instances[0].y;
	if(tecla.action == MLX_PRESS)
	{
		if (tecla.key == MLX_KEY_ESCAPE)
			mlx_close_window(cholo->venti);
		if (tecla.key == MLX_KEY_W && !sepisa(cholo->mapa, *posy/64, *posx/64,'W'))
			mov(cholo,posy,posx,'W');
		if (tecla.key == MLX_KEY_S && !sepisa(cholo->mapa, *posy/64, *posx/64,'S'))
			mov(cholo,posy,posx,'S');
		if (tecla.key == MLX_KEY_A && !sepisa(cholo->mapa, *posy/64, *posx/64,'A'))
			mov(cholo,posy,posx,'A');
		if (tecla.key == MLX_KEY_D && !sepisa(cholo->mapa, *posy/64, *posx/64,'D'))
			mov(cholo,posy,posx,'D');
	}
}
void cogecol(t_cholo *cholo)
{
	int x;
	int y;
	int cnt;
	static int flag = 0;
	
	cnt = 0;
	x = cholo->pnj->instances[0].x/64;
	y = cholo->pnj->instances[0].y/64;
	if(cholo->mapa[y][x] == 'C')
		{ 
			if(cholo->cecoge < cholo->ce && flag == 0)
			{
				while(cholo->colec[cnt]->instances[0].x/64 != x ||cholo->colec[cnt]->instances[0].y/64 != y)
					cnt++;
				cholo->colec[cnt]->enabled = false;
				cholo->mapa[y][x] = '0';
				cholo->cecoge++;
				flag = 1;
			}
			
		}
		else 
			flag = 0;
		
}
void sesale(void *chostruc)
{
	t_cholo *cholo;
	cholo = chostruc;
	cogecol(cholo);
	if(cholo->cecoge == cholo->ce)
	{
		cholo->sal->enabled = true;
		if(cholo->pnj->instances[0].x == cholo->sal->instances[0].x && cholo->pnj->instances[0].y== cholo->sal->instances[0].y)
			{
				ft_putstr_fd("HAS GANADO!!!!!!!! :D \n",0);
				exit(0);
			}
			
	}
}
int	main(int argc, char **argv)
{
	int		fd;
	t_cholo	*cholo;

	cholo = malloc(sizeof(t_cholo));
	cholo->mapa = NULL;
	if (argc == 2)
	{
		boia_ber(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if(fd == -1)
		{
			printf("No hay acceso al archivo\n");
			return(1);
		}
		cholo->mapa = archivo(fd);
		if(cholo->mapa == NULL)
		{
			printf("El mapa está vacío\n");
			return(1);
		}
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if(muros(cholo->mapa) == 1)
		{
			printf("El mapa no está rodeados por muros\n");
			return(1);
		}
		if(recto(cholo->mapa) == 1)
			return(1);
		cholo->ce = ft_validchar(cholo->mapa);
		if(cholo->ce == -1)
			return (1);
		if(only(cholo->mapa) == 1)
			return(1);
		ft_pos(cholo);
	    if(flotfil(cholo->mapa, cholo->pj_x, cholo->pj_y) != cholo->ce + 1)
		{
			return(1);
		}	
		cholo->mapa = fri(cholo->mapa);
		cholo->mapa = archivo(fd);
		cholo->venti = mlx_init(cholo->an * 64, cholo->al * 64, "Cholo Simepone", false);
		textu(cholo); 
		venticar(cholo,cholo->mapa);
		mlx_key_hook(cholo->venti, hoooook, cholo);
		mlx_loop_hook(cholo->venti, sesale, cholo);
		mlx_loop(cholo->venti);
	}
}

// int32_t main(void)
// {
// 	mlx_t *mlx;
// 	mlx_texture_t *fondo;
// 	mlx_texture_t *pnj;
// 	mlx_texture_t *malo;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
// 	if (!mlx)
//  		exit(EXIT_FAILURE);

//  	fondo = mlx_load_png("fondo.png");
// 	pnj = mlx_load_png("pnj.png");
//  	malo = mlx_load_png("malo.png");

// 	g_img = mlx_texture_to_image(mlx, pnj);
//  	mlx_image_to_window(mlx, g_img, 0, 0);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// // mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// 	*¿
 