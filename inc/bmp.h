/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 10:36:49 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/25 18:34:26 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <stdint.h>

# pragma pack(push, 1)

typedef struct		s_header{
	uint16_t	type;
	uint32_t	size;
	uint16_t	reserved1;
	uint16_t	reserved2;
	uint32_t	offset;
	uint32_t	dib_header_size;
	int32_t		width_px;
	int32_t		height_px;
	uint16_t	num_planes;
	uint16_t	bits_per_pixel;
	uint32_t	compression;
	uint32_t	image_size_bytes;
	int32_t		x_resolution_ppm;
	int32_t		y_resolution_ppm;
	uint32_t	num_colors;
	uint32_t	important_colors;
}					t_header;

typedef struct		s_bmp{
	t_header			header;
	unsigned char		*data;
	int					padding;
	int					line_size;
	int					data_size;
}					t_bmp;

# pragma pack(pop)

ssize_t				write_data(int fd, t_window *w);
#endif
