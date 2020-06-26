/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 17:58:01 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 18:48:27 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/bmp.h"

int		is_cube_file(char *str)
{
	char	*s;
	int		fd;
	char	buff[2];
	int		res;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	res = read(fd, buff, 1);
	if (res == -1)
		return (-1);
	s = ft_strrchr(str, '.');
	if (s == NULL)
		return (-1);
	return (ft_strncmp(s, ".cub", 4));
}

void	ft_take_screenshot(t_window *w, char *argv)
{
	int		fd;

	if (ft_strncmp(argv, "--save", ft_strlen(argv)) != 0)
		print_error("Error : !!!   ARG 3 is not ok !!!\n");
	if (w->conf.width > 6000 || w->conf.height > 6000)
		print_error("Error\nScreenshot error\nTry smaller resolution :)\n");
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write_data(fd, w);
	close(fd);
	exit(1);
}

void	check_resolution(t_window *w)
{
	int		height;
	int		width;

	mlx_get_screen_size(w->mlx, &width, &height);
	if (w->conf.width > width || w->conf.height > height)
		mlx_get_screen_size(w->mlx, &w->conf.width, &w->conf.height);
}

int		main(int argc, char **argv)
{
	t_window	w;

	if (argc < 2 || argc > 3)
		print_error("Error : !!!   NB Argument is not OK   !!! \n");
	if (is_cube_file(argv[1]) != 0)
		print_error("Error :  !!!   Not \".cub\"   !!!\n");
	w.conf = new_parser(argv[1]);
	w.k = init_key();
	check_resolution(&w);
	init_player_pos(&w);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, w.conf.width, w.conf.height, "CUBE3D");
	w.array = make_more_images(&w);
	w.textures = get_textures(&w);
	game(&w);
	if (argc == 3)
		ft_take_screenshot(&w, argv[2]);
	mlx_hook(w.win, 17, 0, (int (*)())&exit, 0);
	mlx_hook(w.win, 2, 1L << 0, key_pressed, &w);
	mlx_hook(w.win, 3, 1L << 1, key_release, &w);
	mlx_loop_hook(w.mlx, update, &w);
	mlx_loop(w.mlx);
	return (0);
}
