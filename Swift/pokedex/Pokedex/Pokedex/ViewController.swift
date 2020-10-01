//
//  ViewController.swift
//  Pokedex
//
//  Created by Mouhamed Sourang on 3/16/20.
//  Copyright © 2020 Mouhamed Sourang. All rights reserved.
//

import UIKit

class ViewController: UITableViewController, UISearchBarDelegate {
    
    @IBOutlet var searchbar: UISearchBar!
    var pokemon: [Pokemon] = []
    var PokemonListResult: [Pokemon] = []
    var searching = false
    
    func capitalize(text: String) -> String {
        return text.prefix(1).uppercased() + text.dropFirst()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        searchbar.delegate = self
        
        let url = URL(string: "https://pokeapi.co/api/v2/pokemon?limit=151")
        guard let u = url  else {
            return
        }
        
        URLSession.shared.dataTask(with: u) { (data, response, error) in
            guard let data = data else{
                return
            }
            
            do{
                let pokemonList = try JSONDecoder().decode(PokemonList.self, from: data)
                self.pokemon = pokemonList.results
                DispatchQueue.main.async {
                    self.tableView.reloadData()
                }
            }
            catch let error {
                print("\(error)")
            }
        }.resume()
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if searching {
            return PokemonListResult.count
        }
        else{
            return pokemon.count
        }
    }
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "PokemonCell", for: indexPath)
        if searching {
            cell.textLabel?.text = capitalize(text: PokemonListResult[indexPath.row].name)
        }
        else {
            cell.textLabel?.text = capitalize(text: pokemon[indexPath.row].name)
        }
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if searching{
            if segue.identifier == "PokemonSegue"{
                if let destination = segue.destination as? PokemonViewController {
                    destination.pokemon = PokemonListResult[tableView.indexPathForSelectedRow!.row]
                }
            }
        }
        else {
            if segue.identifier == "PokemonSegue"{
                if let destination = segue.destination as? PokemonViewController{
                    destination.pokemon = pokemon[tableView.indexPathForSelectedRow!.row]
                }
            }
            
        }
    }
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        PokemonListResult = pokemon.filter({$0.name.lowercased().contains(searchText.lowercased())})
        searching = true
        tableView.reloadData()
        if searchText == "" {
            searching = false
            tableView.reloadData()
        }
    
        
    }
    
    
}


