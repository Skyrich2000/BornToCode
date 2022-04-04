#include "minirt.h"

t_texture	create_texture(t_clr color, char *name)
{
    t_texture	texture;

    texture.color = vec_divn(color, 255);
    if (name)
    {
        if (ft_strncmp(name, "checkboard") == 0)
        {
            texture.type = TEXTURE_CHECKERBOARD;
            texture.value = &checkboard_value;
        }
        else if (ft_strncmp(name, "mirror") == 0)
        {
            texture.type = TEXTURE_MIRROR;
            texture.value = &solid_value;
        }
        else
        {
            texture.type = TEXTURE_IMAGE;
            texture.image = mlx_png_file_to_image(m()->scr.mlx, name, \
                                            &texture.width, &texture.height);
            printf("texture loaded: %s\n", name);
            if (!texture.image)
                exit(1);
            texture.addr = mlx_get_data_addr(texture.image, &texture.bits_per_pixel, \
                            &texture.line_length, &texture.endian);
            texture.value = &image_value;
        }
    }
    else
    {
        texture.type = TEXTURE_SOLID;
        texture.value = &solid_value;
    }
    return (texture);
}
