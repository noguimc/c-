const vscode = require('vscode');

class BrowserViewProvider {
    constructor(context) {
        this.context = context;
        this._view = undefined;
    }

    resolveWebviewView(webviewView) {
        this._view = webviewView;
        webviewView.webview.options = {
            enableScripts: true,
            localResourceRoots: []
        };

        webviewView.webview.html = this._getWebviewContent();

        // Handle messages from webview
        webviewView.webview.onDidReceiveMessage(message => {
            switch (message.command) {
                case 'alert':
                    vscode.window.showInformationMessage(message.text);
                    return;
            }
        });
    }

    _getWebviewContent() {
        return `
            <!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Browser</title>
                <style>
                    body {
                        padding: 0;
                        margin: 0;
                    }
                    #controls {
                        padding: 5px;
                        display: flex;
                        gap: 5px;
                    }
                    #browser {
                        width: 100%;
                        height: calc(100vh - 40px);
                        border: none;
                    }
                    input {
                        flex: 1;
                        padding: 5px;
                    }
                    button {
                        padding: 5px 10px;
                    }
                </style>
            </head>
            <body>
                <div id="controls">
                    <button onclick="goBack()">←</button>
                    <button onclick="goForward()">→</button>
                    <button onclick="refresh()">⟳</button>
                    <input type="text" id="urlInput" placeholder="Enter URL" onkeydown="if(event.key==='Enter')navigate()">
                    <button onclick="navigate()">Go</button>
                </div>
                <iframe id="browser" src="https://www.google.com"></iframe>
                <script>
                    const iframe = document.getElementById('browser');
                    const urlInput = document.getElementById('urlInput');

                    function navigate() {
                        let url = urlInput.value;
                        if (!url.startsWith('http://') && !url.startsWith('https://')) {
                            url = 'https://' + url;
                        }
                        iframe.src = url;
                    }

                    function goBack() {
                        history.back();
                    }

                    function goForward() {
                        history.forward();
                    }

                    function refresh() {
                        iframe.src = iframe.src;
                    }
                </script>
            </body>
            </html>
        `;
    }
}

function activate(context) {
    const provider = new BrowserViewProvider(context);

    context.subscriptions.push(
        vscode.window.registerWebviewViewProvider('vscode-browser.browserView', provider)
    );

    // Register commands
    context.subscriptions.push(
        vscode.commands.registerCommand('vscode-browser.refresh', () => {
            if (provider._view) {
                provider._view.webview.postMessage({ command: 'refresh' });
            }
        })
    );

    context.subscriptions.push(
        vscode.commands.registerCommand('vscode-browser.goBack', () => {
            if (provider._view) {
                provider._view.webview.postMessage({ command: 'goBack' });
            }
        })
    );

    context.subscriptions.push(
        vscode.commands.registerCommand('vscode-browser.goForward', () => {
            if (provider._view) {
                provider._view.webview.postMessage({ command: 'goForward' });
            }
        })
    );
}

function deactivate() {}

module.exports = {
    activate,
    deactivate
};
