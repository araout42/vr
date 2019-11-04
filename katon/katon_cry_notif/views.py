from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.contrib.auth import login, authenticate
from django.contrib.auth.forms import UserCreationForm
from .forms import SignupForm

def index(request):
    return(render(request, 'index.html'))

def connection(request):
    return(render(request, 'connection.html'))

def settings(request):
    return (HttpResponse("settings"))

def register(request):
    if request.method == 'POST':
        form = SignupForm(request.POST)
        if (form.is_valid()):
            form.save()
            username = form.cleaned_data.get('username')
            raw_password = form.cleaned_data.get('password1')
            user = authenticate(username=username, password=raw_password)
            login(request,user)
            return (redirect(home))
    else:
        form = SignupForm()
    return(render(request, 'register.html', {'form':form}))
