/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:07:28 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_SCENE_H
# define ENGINE_SCENE_H
# include "engine/engine_image.h"
# include "engine/engine_scene.h"

typedef struct s_scene
{
	t_background	*background;
	void			(*start)(void);
	void			(*controller)(void);
	void			(*ui)(void);
	void			(*end)(void);
}	t_scene;

// manage scene asset
t_scene			*add_scene(t_background *background, void (*start)(void), \
				void (*controller)(void), void (*ui)(void), void (*end)(void));

// scene manage function
void			scene_start(void);
void			scene_change(t_scene *scene);
void			scene_restart(void);
void			scene_end(void);

#endif
