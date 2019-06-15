/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/06/13 18:03:20 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op    op_tab[REG_NUMBER + 1] =
{
//	ins		len_ins	len_params		params										opcode	cycle	description								indirect	direct
	{"live",	4,	1,	{T_DIR},												LIVE,	10,		"alive",									0,	0},
	{"ld",		2,	2,	{T_DIR | T_IND, T_REG},									LD,		5,		"load",										1,	0},
	{"st",		2,	2,	{T_REG, T_IND | T_REG},									ST,		5,		"store",									1,	0},
	{"add",		3,	3,	{T_REG, T_REG, T_REG},									ADD,	10,		"addition",									1,	0},
	{"sub",		3,	3,	{T_REG, T_REG, T_REG},									SUB,	10,		"soustraction",								1,	0},
	{"and",		3,	3,	{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},	AND,	6,		"et (and  r1, r2, r3   r1&r2 -> r3",		1,	0},
	{"or",		2,	3,	{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},	OR,		6,		"ou  (or   r1, r2, r3   r1 | r2 -> r3",		1,	0},
	{"xor",		3,	3,	{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},	XOR,	6,		"ou (xor  r1, r2, r3   r1^r2 -> r3",		1,	0},
	{"zjmp",	4,	1,	{T_DIR},												ZJMP,	20,		"jump if zero",								0,	1},
	{"ldi",		3,	3,	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},			LDI,	25,		"load index",								1,	1},
	{"sti",		3,	3,	{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},			STI,	25,		"store index",								1,	1},
	{"fork",	4,	1,	{T_DIR},												FORK,	800,	"fork",										0,	1},
	{"lld",		3,	2,	{T_DIR | T_IND, T_REG},									LLD,	10,		"long load",								1,	0},
	{"lldi",	4,	3,	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},			LLDI,	50,		"long load index",							1,	1},
	{"lfork",	5,	1,	{T_DIR},												LFORK,	1000,	"long fork",								0,	1},
	{"aff",		3,	1,	{T_REG},												AFF,	2,		"aff",										1,	0},
	{0,			0,	0,	{0},													0,		0,		0,											0,	0}
};
