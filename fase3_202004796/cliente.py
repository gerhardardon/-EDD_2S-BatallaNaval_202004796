from pip._vendor import requests
import json

base_url = "http://localhost:8080"
mainUser ="."

def req_login(name,contra):
    global mainUser
    mainUser=name
    print(mainUser)

    usuario = {'nick': name ,'password': contra}
    x = requests.post(f'{base_url}/login', json = usuario)
    print(x.status_code)
    return x.status_code

def req_edit(user, new_user ,new_pass,new_age):
    usuario = {'user': user ,'new_user': new_user, 'new_pass': new_pass,'new_age': new_age}
    x = requests.post(f'{base_url}/edit', json = usuario)
    print(x.status_code)
    return x.status_code

def req_erase(name):
    usuario = {'user': name }
    x = requests.post(f'{base_url}/erase', json = usuario)
    print(x.status_code)
    return x.status_code

def req_create(user, contra ,age,id):
    usuario = {'user': user ,'pass': contra, 'age': age,'id': id}
    x = requests.post(f'{base_url}/create', json = usuario)
    print(x.status_code)
    return x.status_code

def req_agregar_mov(posx,posy):
    usuario = {'x': posx,"y":posy }
    x = requests.post(f'{base_url}/agregar_mov', json = usuario)
    print(x.status_code)
    return x.status_code

def req_regresar_mov():
    x = requests.get(f'{base_url}/regresar_mov') 
    print(x.status_code)
    return x.status_code

def req_agregar_tkns(name):
    usuario = {'user': name }
    x = requests.post(f'{base_url}/agregar_tokens', json = usuario)
    print(x.status_code)
    return x.status_code

def req_reportes():
    x = requests.get(f'{base_url}/reportes') 
    print(x.status_code)
    return x.status_code