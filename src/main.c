/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 17:58:01 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/21 19:29:57 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/bmp.h"

int		is_cube_file(char *str)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (s == NULL)
		return (-1);
	return (ft_strncmp(s, ".cub", 4));
}


void	ft_take_screenshot(t_window *w)
{
		int		fd;
	
		fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        write_data(fd, w);
        close(fd);
		exit(1);
}

int		main(int argc, char **argv)
{
	t_window	w;

	if(argc < 2 || argc > 3)
		print_error("Error : !!!   NB Argument is not OK   !!! \n");
	if(is_cube_file(argv[1]) != 0)
		print_error("Error :  !!!   Not \".cub\"   !!!\n");
	w.conf = parse_map(argv[1]);
	w.k = init_key();
	init_player_pos(&w);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, w.conf.width, w.conf.height, "CUBE3D");
	w.array = make_more_images(&w);
	w.textures = get_textures(&w);
	game(&w);
	if(argc == 3)
	{
		if(ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0)
			print_error("Error : !!!   ARG 3 is not ok !!!\n");
		ft_take_screenshot(&w);

	}
	mlx_hook(w.win, 2, 1L << 0, key_pressed, &w);
	mlx_hook(w.win, 3, 1L << 1, key_release, &w);
	mlx_loop_hook(w.mlx, update, &w);
	mlx_loop(w.mlx);
	return (0);
}
