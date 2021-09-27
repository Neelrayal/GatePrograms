# I have created this file.

from django.http import HttpResponse
from django.shortcuts import render
def index(request):
    params = {
        'name': 'neel',
        'place': 'kalol'
    }
    return render(request, 'index.html', params)

#changed the value of index because vid 8 requires templates. This was last used in vid 6
def index7(request):
    return HttpResponse('''
    <head>
      <title>Bootstrap Example</title>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
      <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    </head>


        <div class="container">
          <h2>My Django project</h2>                    
          <a href = removepunc><input type="button" class="btn btn-info" value="remove punc" ahref = 'gmail.com'></a>
          <a href = capitalizefirst><input type="submit" class="btn btn-info" value="cap first"></a>
          <a href = newlineremove><input type="submit" class="btn btn-info" value="new line remove"></a>
          <a href = spaceremove><input type="submit" class="btn btn-info" value="space remove"></a>
          <a href = charcount><input type="submit" class="btn btn-info" value="char count"></a>
        </div>
    ''')


def about(request):
    return HttpResponse('this is about section')


def openfile(request):
    f = open(r'C:\Users\neelr_rzc8ain\PycharmProjects\DjangoCourse\mysite\mysite\file1.txt', 'r')
    return HttpResponse(f)

def personalnavigator(request):
    return HttpResponse('''
    <a href="https://www.w3schools.com">Visit W3Schools.com!</a><br>
    <a href = 'youtube.com'> Goto Youtube</a><br>
    <a href = 'spotify.com'>Goto spotify </a><br>
    <a href = 'gmail.com'> Goto Gmail </a><br>
    <a href = 'facebook.com'> Goto Facebook </a><br>
    ''')

#video 7, 9
def removepunc(request):
    djtext = request.GET.get('text', 'default')
    print(djtext)
    #Analyze the text

    return HttpResponse('remove punc')

def capfirst(request):
    return HttpResponse('capitalize first')

def newlineremove(request):
    return HttpResponse('newline first')

def spaceremove(request):
    return HttpResponse('space remover')

def charcount(request):
    return HttpResponse('char count')

#vid 10
def analyze(request):
    #get the text
    djtext = request.GET.get('text', 'default')
    removepunc = request.GET.get('removepunc', 'off')
    fullcaps = request.GET.get('fullcaps','off')
    newlineremover = request.GET.get('newlineremover','off')
    extraspaceremover = request.GET.get('extraspaceremover', 'off')
    charcounter = request.GET.get('charcounter', 'off')
    analyzed = ""
    new_djtext = ""
    charcount = 0

    if removepunc == 'on':
        punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
        for char in djtext:
            if char not in punctuations:
                analyzed += char
        params = {
            'purpose': 'remove the punctuations',
            'analyzed_text' : new_djtext
        }
        #return render(request, 'analyze.html', params)
    if removepunc == 'off':
        new_djtext = djtext
    else:
        new_djtext = analyzed

    if fullcaps == 'on':
        analyzed = ""
        for char in new_djtext:
            analyzed = analyzed + char.upper()

        params = {
            'purpose': 'changed to upper case',
            'analyzed_text' : new_djtext
        }
        #return render(request, 'analyze.html', params)
    new_djtext = analyzed
    if newlineremover == 'on':
        analyzed = ""
        for char in new_djtext:
            if char != '\n':
                analyzed = analyzed + char

        params = {
            'purpose': 'removed the new lines',
            'analyzed_text' : new_djtext
        }
        #return render(request, 'analyze.html', params)
    new_djtext = analyzed
    if extraspaceremover == 'on':
        analyzed = ""
        for index, char in enumerate(new_djtext):
            if not ( new_djtext[index] == " " and new_djtext[index+1] == " "):
                analyzed = analyzed + char

        params = {
            'purpose': 'removed the extra spaces',
            'analyzed_text' : new_djtext
        }
        #return render(request, 'analyze.html', params)
    new_djtext = analyzed
    if charcounter == 'on':
        charcount = len(new_djtext)
        params = {
            'purpose': ' Counting number of characters',
            'analyzed_text' : new_djtext,
            'char_counted': charcount
        }
        #return render(request, 'analyze.html', params)
    if (charcounter or extraspaceremover or newlineremover or fullcaps or removepunc):
        return render(request, 'analyze.html', params)
    else:
        return HttpResponse('Error')



