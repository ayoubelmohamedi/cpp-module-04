/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:19:20 by macbookpro        #+#    #+#             */
/*   Updated: 2025/04/04 11:58:43 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const std::string& name);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    const std::string& getName() const;
    void setName(const std::string& name);
    std::string getType();

};

#endif