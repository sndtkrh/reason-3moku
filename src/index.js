import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import {make as Game} from "./game.bs.js"

// =====
ReactDOM.render(
    <Game />,
    document.getElementById('root')
);
