#ifndef CXX_TYPE_NAME_H
#define CXX_TYPE_NAME_H

#include <memory>
#include <string>
#include <vector>

#include "data/name/NameHierarchy.h"
#include "data/parser/cxx/name/CxxName.h"
#include "data/parser/cxx/name/CxxQualifierFlags.h"

class CxxTypeName: public CxxName
{
public:
	static std::shared_ptr<CxxTypeName> makeUnsolvedIfNull(std::shared_ptr<CxxTypeName> name);

	struct Modifier
	{
		Modifier(std::string&& symbol);
		std::string symbol;
		CxxQualifierFlags qualifierFlags;
	};

	// uncomment this constructor if required, but try to use the one using move constructors for the members
	//CxxTypeName(
	//	const std::string& name,
	//	const std::vector<std::string>& templateArguments
	//);

	CxxTypeName(
		std::string&& name,
		std::vector<std::string>&& templateArguments
	);

	// uncomment this constructor if required, but try to use the one using move constructors for the members
	//CxxTypeName(
	//	const std::string& name,
	//	const std::vector<std::string>& templateArguments,
	//	std::shared_ptr<CxxName> parent
	//);

	CxxTypeName(
		std::string&& name,
		std::vector<std::string>&& templateArguments,
		std::shared_ptr<CxxName> parent
	);

	virtual NameHierarchy toNameHierarchy() const;

	void addQualifier(const CxxQualifierFlags::QualifierType qualifier);
	void addModifier(const Modifier& modifier);

	std::string toString() const;

private:
	std::string getTypeNameString() const;

	std::string m_name;
	std::vector<std::string> m_templateArguments;

	CxxQualifierFlags m_qualifierFlags;
	std::vector<Modifier> m_modifiers;
};

#endif // CXX_TYPE_NAME_H
