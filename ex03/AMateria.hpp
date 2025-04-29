/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:39:05 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/29 18:21:57 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp" 

class ICharacter;
class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        virtual ~AMateria();

        AMateria & operator=(AMateria const & rhs);

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif