/*==========================================================================

  © Université de Strasbourg - Centre National de la Recherche Scientifique

  Date: 22/03/2012
  Author(s): Schweitzer Marc (marc.schweitzer@unistra.fr)

  This software is governed by the CeCILL-B license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL-B
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.

  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-B license and that you accept its terms.

==========================================================================*/

#ifndef __BTKMACRO_H__
#define __BTKMACRO_H__

#include "iostream"

#include "itkWin32Header.h"
#include "itkConfigure.h"
#include "itkMacro.h"

#include <string>


namespace btk
{
//-------------------------------------------------------------------------------------------------------------------
#define btkGetMacro(name, type)                                   \
virtual type Get##name () const                                   \
{                                                                 \
    return this->m_##name;                                        \
}
//-------------------------------------------------------------------------------------------------------------------
#define btkSetMacro(name, type)                                   \
virtual void Set##name (type _arg)                          \
{                                                                 \
    if ( this->m_##name != _arg )                                 \
    {                                                             \
        this->m_##name = _arg;                                    \
    }                                                             \
}
//-------------------------------------------------------------------------------------------------------------------
#define btkConstSetMacro(name, type)                           \
virtual void Set##name (const type _arg)                                \
{                                                                 \
    if ( this->m_##name != _arg )                                 \
    {                                                             \
        this->m_##name = _arg;                                    \
    }                                                             \
}
//-------------------------------------------------------------------------------------------------------------------
#define btkPureVirtualGetMacro(name, type)                         \
virtual type Get##name () = 0
//-------------------------------------------------------------------------------------------------------------------
#define btkPureVirtualSetMacro(name, type)                         \
virtual void Set##name (const type _arg)  = 0
//-------------------------------------------------------------------------------------------------------------------
#define btkCoutMacro(string)        std::cout << string << std::endl;
//-------------------------------------------------------------------------------------------------------------------
#define btkCoutVariable(variable)   std::cout << #variable << ": " << variable <<std::endl;
//-------------------------------------------------------------------------------------------------------------------
#define btkCerrMacro(string)        std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " << string << std::endl;
//-------------------------------------------------------------------------------------------------------------------
#define btkWarningMacro(string)     std::cerr << "(" << __FILE__ << ":" << __LINE__ << ")" << "Btk Warning: " << string << std::endl;
//-------------------------------------------------------------------------------------------------------------------
#define btkException(string)        \
    itk::ExceptionObject error;     \
    error.SetDescription(string);   \
    throw(error);                   \
//-------------------------------------------------------------------------------------------------------------------
//TODO: To be continued with const, pointer, string, vector...etc.
//-------------------------------------------------------------------------------------------------------------------
//Macro From btkUserMacro.h
//TODO: Remove Old include of btkUserMacro in all btk files, and replace by this one

//-------------------------------------------------------------------------------------------------------------------
/** Set built-in type.  Creates member Set"name"() (e.g., SetVisibility()); */
#define itkSetMacroNoDeb(name,type) \
  virtual void Set##name (const type _arg) \
  { \
    if (this->m_##name != _arg) \
      { \
      this->m_##name = _arg; \
      this->Modified(); \
      } \
  }
//-------------------------------------------------------------------------------------------------------------------
/** Get built-in type.  Creates member Get"name"() (e.g., GetVisibility()); */
#define itkGetMacroNoDeb(name,type) \
  virtual type Get##name () \
  { \
    return this->m_##name; \
  }
//-------------------------------------------------------------------------------------------------------------------
/** Set built-in type.  Creates member Set"name"() (e.g., SetVisibility()); */
#define UserSetMacro(name,type) \
  virtual void Set##name (int i, const type _arg) \
  { \
    itkDebugMacro("setting " #name " to " << _arg); \
    if (this->m_##name[i] != _arg) \
      { \
      this->m_##name[i] = _arg; \
      this->Modified(); \
      } \
  }
//-------------------------------------------------------------------------------------------------------------------
/** Set pointer to object; uses Object reference counting methodology.
 * Creates method Set"name"() (e.g., SetPoints()). Note that using
 * smart pointers requires using real pointers when setting input,
 * but returning smart pointers on output. */
#define UserSetObjectMacro(name,type) \
  virtual void Set##name (int i, type* _arg ) \
  { \
    if (this->m_##name[i] != _arg) \
      { \
      this->m_##name[i] = _arg; \
      this->Modified(); \
      } \
  }
//-------------------------------------------------------------------------------------------------------------------
/** Get a smart pointer to an object.  Creates the member
 * Get"name"() (e.g., GetPoints()). */
#define UserGetObjectMacro(name,type) \
  virtual type * Get##name (int i) \
  { \
    itkDebugMacro("returning " #name " address " << this->m_##name[i] ); \
    return this->m_##name[i].GetPointer(); \
  }
//-------------------------------------------------------------------------------------------------------------------
/** Set const pointer to object; uses Object reference counting methodology.
 * Creates method Set"name"() (e.g., SetPoints()). Note that using
 * smart pointers requires using real pointers when setting input,
 * but returning smart pointers on output. */
#define UserSetConstObjectMacro(name,type) \
  virtual void Set##name (int i, const type* _arg) \
  { \
    itkDebugMacro("setting " << #name " to " << _arg ); \
    if (this->m_##name[i] != _arg) \
      { \
      this->m_##name[i] = _arg; \
      this->Modified(); \
      } \
  }

//-------------------------------------------------------------------------------------------------------------------
/** Get a smart const pointer to an object.  Creates the member
 * Get"name"() (e.g., GetPoints()). */
#define UserGetConstObjectMacro(name,type) \
  virtual const type * Get##name (int i) const \
  { \
    itkDebugMacro("returning " #name " address " << this->m_##name[i] ); \
    return this->m_##name[i].GetPointer(); \
  }
//-------------------------------------------------------------------------------------------------------------------
/** Get a const reference to a smart pointer to an object.
 * Creates the member Get"name"() (e.g., GetPoints()). */
#define UserGetConstReferenceObjectMacro(name,type) \
  virtual const typename type::Pointer & Get##name (int i) const \
  { \
    itkDebugMacro("returning " #name " address " << this->m_##name[i] ); \
    return this->m_##name[i]; \
  }
//-------------------------------------------------------------------------------------------------------------------

}
#endif
