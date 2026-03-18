<div align="center">
  <h1>🚀 Keystroke Autocomplete Engine ⌨️</h1>

  <p>
    <img src="https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++17" />
    <img src="https://img.shields.io/badge/CMake-3.14+-064F8C?style=for-the-badge&logo=cmake&logoColor=white" alt="CMake" />
    <img src="https://img.shields.io/badge/UI-FTXUI-FF7139?style=for-the-badge&logo=appveyor&logoColor=white" alt="FTXUI" />
    <img src="https://img.shields.io/badge/License-MIT-success?style=for-the-badge" alt="License" />
  </p>

  <h3>✨ Feel the magic of smart text prediction right in your terminal! ✨</h3>
  <p>
    <b>A lightning-fast, event-driven autocomplete backend for modern keyboard input.</b><br>
    <sub>Powered by a frequency-weighted Trie and wrapped in a beautiful, reactive interface.</sub>
  </p>
</div>

<hr>

> **💡 What is this?**
> Ever wondered how your smartphone guesses your next word so quickly? This engine brings that exact magic to the terminal. It doesn't wait for you to hit `ENTER` — it analyzes every single keystroke in real-time, instantly offering the most relevant suggestions!

<h2>🌟 Why is it so awesome? (Key Features)</h2>

<ul>
  <li><b>⚡ Lightning-Fast Prefix Routing:</b> Thanks to the Trie structure, navigating to your exact keystrokes is instantaneous — it's a strict <code>O(Length)</code> operation! From that exact node, the engine harvests every single matching word and dynamically sorts them on the fly to surface the absolute best suggestions.</li>
  <li><b>🧠 It Knows What You Want (Smart BFS):</b> This isn't just a dumb alphabetical list. The algorithm uses a Breadth-First Search to rank and surface the exact words you are most likely to use based on actual frequency weights.</li>
  <li><b>🔠 It Respects Your <code>Shift</code> Key:</b> Typing <code>Ala</code>? You get <code>Alarm</code>. Typing <code>ala</code>? You get <code>alarm</code>. The engine intelligently inherits your capitalization so you never have to go back and fix it.</li>
  <li><b>✂️ Multi-Word Magic:</b> The engine seamlessly tokenizes your input on the fly, ensuring it always focuses on predicting just the <i>current</i> word you are actively typing.</li>
  <li><b>🎨 Gorgeous Interface (TUI):</b> Who said the terminal has to be boring? Using the FTXUI library, we've built a fully reactive, visually appealing interface that updates smoothly with every key press.</li>
</ul>

<h2>🛠️ How to run it? (Getting Started)</h2>
<p>Thanks to the power of CMake's <code>FetchContent</code>, there is zero manual dependency hunting. The magic happens automatically in the background! 🪄</p>

<h3>📦 1. Grab the code</h3>
<pre><code>git clone https://github.com/ptrzebinski/autocomplete-keyboard.git
cd autocomplete-keyboard</code></pre>

<h3>⚙️ 2. Build the engine (Turning on the -O3 boosters!)</h3>
<pre><code>cmake -B build -S .
cmake --build build</code></pre>

<h3>🚀 3. Fire it up!</h3>
<pre><code>./build/autocomplete_keyboard</code></pre>

<h2>🎮 Controls &amp; Usage</h2>
<ul>
  <li>⌨️ <b>Just Type:</b> Watch the suggestion engine react instantly to your alphanumeric input.</li>
  <li><kbd>Space</kbd> <b>(Spacebar):</b> Commits the current word and smoothly resets the search buffer for the next one.</li>
  <li><kbd>Backspace</kbd> <b>(Erase):</b> Dynamically trims your prefix and recalculates the Trie traversal in a split second.</li>
  <li><kbd>Ctrl</kbd> + <kbd>C</kbd> <b>(Exit):</b> Safely terminates the app and triggers a strict memory cleanup (Zero memory leaks! 🛡️).</li>
</ul>

<hr>

<div align="center">
  <p><i>Engineered with passion for C++, extreme performance, and beautiful code. 💻❤️</i></p>
</div>