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
    djtext = request.POST.get('text', 'default')
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
    djtext = request.POST.get('text', 'default')
    removepunc = request.POST.get('removepunc', 'off')
    fullcaps = request.POST.get('fullcaps','off')
    newlineremover = request.POST.get('newlineremover','off')
    extraspaceremover = request.POST.get('extraspaceremover', 'off')
    charcounter = request.POST.get('charcounter', 'off')
    analyzed = ""
    funcCount = 0
    charcount = 0

    if removepunc == 'on':
        funcCount += 1
        punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
        for char in djtext:
            if char not in punctuations:
                analyzed += char
        djtext = analyzed
        params = {
            'purpose': 'remove the punctuations',
            'analyzed_text' : analyzed
        }
        #return render(request, 'analyze.html', params)

    if fullcaps == 'on':
        funcCount += 1
        analyzed = ""
        for char in djtext:
            analyzed = analyzed + char.upper()
        print('fullcaps text: ', analyzed)
        djtext = analyzed
        params = {
            'purpose': 'changed to upper case',
            'analyzed_text' : analyzed
        }
        #return render(request, 'analyze.html', params)

    if newlineremover == 'on':
        funcCount += 1
        analyzed = ""
        for char in djtext:
            if char != '\n' and  char != '\r': # carrige return is used to tranport newline to backend. maybe same as stray character
                analyzed = analyzed + char
        djtext = analyzed
        params = {
            'purpose': 'removed the new lines',
            'analyzed_text' : analyzed
        }
        #return render(request, 'analyze.html', params)

    if extraspaceremover == 'on':
        print('Here !!')
        funcCount += 1
        analyzed = ""
        for index, char in enumerate(djtext):
            if not ( djtext[index] == " " and djtext[index+1] == " "):
                analyzed = analyzed + char
        djtext = analyzed
        params = {
            'purpose': 'removed the extra spaces',
            'analyzed_text' : analyzed
        }
        #return render(request, 'analyze.html', params)
    if charcounter == 'on':
        funcCount += 1
        print(djtext)
        charcount = len(djtext)
        params = {
            'purpose': ' Counting number of characters',
            'analyzed_text' : djtext,
            'char_counted': charcount
        }
        #return render(request, 'analyze.html', params)

    if (funcCount):
        if funcCount > 1:
            params['purpose'] = 'multiple purpose'
        print('final text is:\n',params['analyzed_text'])
        return render(request, 'analyze.html', params)
    else:
        return HttpResponse('No operation selected')



