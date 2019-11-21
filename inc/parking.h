/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parking.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:23:07 by nicktor           #+#    #+#             */
/*   Updated: 2019/11/21 11:04:39 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARKING_H
# define PARKING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
**			affiche_map.c
*/
void	affiche_map(char *fichier);
/*
**			affiche_map.c
*/
void	affiche_voiture(char *fichier, int x, int y, int d);
/*
**			efface_map.c
*/
void	efface_voiture(int x, int y);

#endif
