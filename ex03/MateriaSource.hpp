/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:40:18 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/05 10:40:19 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4];
    
    void _clearTemplates();
    
public:
    MateriaSource();
    MateriaSource(MateriaSource const & src);
    virtual ~MateriaSource();
    
    MateriaSource & operator=(MateriaSource const & rhs);
    
    // IMateriaSource implementation
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif