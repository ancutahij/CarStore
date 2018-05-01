#include"FileRepository.h"
#pragma once


class UndoAction
{
	/*
		An abstract class from which other classes (like UndoAddAction, UndoUpdateAction, UndoDeleteAction) will inherit
		The undo option for CRUD operations from repository is implemented by memorizing the actions that have been made and not saving the current list
		everytime when a change is made.
		For instance:
		If a car is added, the opposite operation is removing
		If a car is deleting, the opposite operation is adding
	*/
public:
	virtual void doUndo()=0;
	virtual ~UndoAction()
	{
		//std::cout << "Base";
	}
};

class UndoAddAction : public UndoAction
{
	Car car;
	Repository& repo;
public:
	UndoAddAction(Repository& repo, const Car& car)
		: repo(repo), car(car) {}
	void doUndo() override { repo.deleteElement(car.getRegistration()); }
	~UndoAddAction()
	{
		//std::cout << "Derived";

	}
};

class UndoDeleteAction : public UndoAction
{
	Car car;
	Repository& repo;
public:
	UndoDeleteAction(Repository& repo, const Car& car)
		: repo(repo), car(car) {}
	void doUndo() override { repo.addNewElement(car); }
	~UndoDeleteAction()
	{
	}
};


class UndoUpdateAction : public UndoAction
{
	Car car;
	Repository& repo;
public:
	UndoUpdateAction(Repository& repo, const Car& car)
		: repo(repo), car(car) {}
	void doUndo() override { repo.deleteElement(car.getRegistration()); repo.addNewElement(car); }
	~UndoUpdateAction()
	{
	}
};