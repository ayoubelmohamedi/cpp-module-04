#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp" 

class ICharacter; // Forward declaration

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const & type);
        AMateria(AMateria const & src); 
        virtual ~AMateria();

        AMateria & operator=(AMateria const & rhs); // (rule of three)

        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0; // Pure virtual function
        virtual void use(ICharacter& target); // Virtual function
};

#endif