/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {

    void Department::updateName(const char* newname) {
        delete[] m_name;
        if (newname != nullptr && newname[0] != '\0'){
            m_name = new char[strlen(newname) + 1];
            strcpy(m_name, newname);
        } 

    }

    void Department::updateBudget(double change) {
        m_budget += change;
    }

    bool Department::addProject(Project& newproject) {
        bool success   {};
        if ((totalexpenses() + newproject.m_cost) <= m_budget)
        {
            if (m_noProjects == 0) {
                m_projects = new Project[1];                     
                *m_projects = newproject;
                m_noProjects++;
            }
            else {
                Project* tempProjects = new Project[++m_noProjects];
                for (int i = 0; i < m_noProjects-1; i++)
                    tempProjects[i] = m_projects[i];
                tempProjects[m_noProjects-1] = newproject;

                delete[] m_projects;
                m_projects = nullptr;
                m_projects = tempProjects;   
            }
            success =  true;
        }
        else   success = false;
        return success;
    }

    void Department::createDepartment(const char *newname,
                                      Project &newproject,
                                      double change) {
        updateName(newname);
        updateBudget(change);
        addProject(newproject);
    }

    Project *Department::fetchProjects() const {
        return m_projects;
    }

    int Department::fetchNumProjects() const {
        return m_noProjects;
    }

    double Department::fetchBudget() const {
        return m_budget;
    }

    char *Department::fetchName() const {
        return m_name;
    }

    double Department::totalexpenses() {
        double total_expenses = 0.0;
        
        for(int i = 0; i < m_noProjects; i++)
            total_expenses += m_projects[i].m_cost;

        return total_expenses;
    }

    double Department::remainingBudget() {
        return m_budget - totalexpenses();
    }

    void Department::clearDepartment() {
            delete[] m_projects;
            delete[] m_name;
            m_name = nullptr;
            m_projects = nullptr;
    }
    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    Department::~Department() {
        delete[] m_projects;
        delete[] m_name;
    }

}