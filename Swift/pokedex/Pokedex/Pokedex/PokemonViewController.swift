//
//  PokemonViewController.swift

//  Pokedex
//
//  Created by Mouhamed Sourang on 3/17/20.
//  Copyright © 2020 Mouhamed Sourang. All rights reserved.
//

import UIKit
class PokemonViewController: UIViewController {
    
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var numberLabel: UILabel!
    @IBOutlet var type1Label: UILabel!
    @IBOutlet var type2Label: UILabel!
    @IBOutlet var cath: UIButton!
    let defaults = UserDefaults.standard
    var pokemon: Pokemon!
    var isCaught = false
    @IBOutlet weak var Pokeimage: UIImageView!
    @IBOutlet weak var PokeText: UITextView!
    
    // Func when the user press the catch button
    @IBAction func togglecCath() {
        setCatchTitle()
        saveCatchStatus()
    }
    
    // Func sets the title when the users press the catch button
    func setCatchTitle() {
        
        if isCaught {
            cath.setTitle("Catch", for: .normal)
            isCaught = false
        }
        else {
            cath.setTitle("Release", for: .normal)
            isCaught = true
        }
    }
    
    // Func to save the catch status into Userdefault
    func saveCatchStatus() {
        defaults.set(isCaught, forKey: pokemon.name)
    }
    
    // Func to check the catch status, when view is load
    func didCaught()  {
        let catchStatus = defaults.bool(forKey: pokemon.name)
        if catchStatus {
            isCaught = catchStatus
            loadCatchTitle()
        }
    }
    
    func loadCatchTitle () {
        if isCaught {
            cath.setTitle("Release", for: .normal)
        }
        else {
            cath.setTitle("Catch", for: .normal)
        }
    }
    
    func capitalize(text: String) -> String {
        return text.prefix(1).uppercased() + text.dropFirst()
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        type1Label.text = ""
        type2Label.text = ""
        PokeText.text = ""
        didCaught()
        
        let url = URL(string: pokemon.url)
        guard let u = url  else {
            return
        }
        URLSession.shared.dataTask(with: u) { (data, response, error) in
            guard let data = data else {
                return
            }
            do{
                let pokemonlist = try JSONDecoder().decode(PokemonData.self, from: data)
                DispatchQueue.main.async {
                    self.nameLabel.text = self.capitalize(text: self.pokemon.name)
                    self.numberLabel.text = String(format: "#%03d", pokemonlist.id)
                    
                    //Fetch image in the URL and displays it in the UIimageView
                    for (imageName , imageLink ) in pokemonlist.sprites {
                        if imageName == "front_default" {
                            let getLink = URL(string:imageLink!)
                            guard let imageData = try? Data(contentsOf: getLink!) else { return }
                            let image = UIImage(data: imageData)
                            self.Pokeimage.image = image
                        }
                    }
                    
                    let url2 = URL(string: pokemonlist.species.url)
                    guard let u2 = url2 else {
                        return
                    }
                    URLSession.shared.dataTask(with: u2) { (data, response, error) in
                        guard let data = data else {
                            return
                        }
                        
                        do {
            
                            let PokemonDesResult = try  JSONDecoder().decode(PokemonDescription.self, from: data)
                            
                            DispatchQueue.main.async {
                                for text in PokemonDesResult.flavor_text_entries {
                                    if text.language.name == "en"{
                                    self.PokeText.text = text.flavor_text}
                                }
                            }
                        }
                            //Filter for en and assign text to UItext
                            
                        catch let error {
                            print("\(error)")
                        }
                    }.resume()
                    for typeEntry in pokemonlist.types {
                        if typeEntry.slot == 1 {
                            self.type1Label.text = self.capitalize(text: typeEntry.type.name)
                        }
                        else if typeEntry.slot == 2 {
                            self.type2Label.text = self.capitalize(text: typeEntry.type.name)
                        }
                    }
                }
            }
            catch let error {
                print("\(error)")
            }
        }.resume()
        
    }
}


