/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:19:06 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:19:14 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define FRAME_UNIT				2
# define EMPTY_COLOR			0x229D6E

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17

# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_4					21
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35
# define KEY_J					38
# define KEY_K					40
# define KEY_L					37
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_FORWARD			126
# define KEY_BACKWARD			125
# define KEY_SPACE				49
# define KEY_LSHIFT				257
# define KEY_RSHIFT				258
# define KEY_ESC				53

# define FLAG_UI				0x00000001
# define FLAG_SHADOWS			0x00000010

# ifndef PARS_NUM
#  define PARS_NUM				16
#  define PARS_TEX				7
#  define PARS_ANI				11
#  define P_R					0
#  define P_NO					1
#  define P_SO					2
#  define P_WE					3
#  define P_EA					4
#  define P_CT					5
#  define P_FT					6
#  define P_S					7
#  define P_A3					8
#  define P_A4					9
#  define P_A5					10
#  define P_A6					11
#  define P_C					12
#  define P_F					13
#  define P_T					14
#  define P_MAP					15
# endif

# ifndef TEXTURES_NUM
#  define TEXTURES_NUM			7
#  define TEX_NORTH				0
#  define TEX_SOUTH				1
#  define TEX_WEST				2
#  define TEX_EAST				3
#  define TEX_CEIL				4
#  define TEX_FLOOR				5
#  define TEX_SPRITE			6
# endif

# ifndef ANIMATION_NUM
#  define ANIMATION_NUM			4
#  define ANI_3					0
#  define ANI_4					1
#  define ANI_5					2
#  define ANI_6					3
# endif

# ifndef VALID_MAP_CHARACTERS
#  define VALID_MAP_CHARACTERS " 012345NSEW"
# endif

# ifndef BEST_RATIO
#  define BEST_RATIO			1.7777777778
# endif

#endif
